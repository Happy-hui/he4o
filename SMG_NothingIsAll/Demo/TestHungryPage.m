//
//  TestHungryPage.m
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/7/9.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import "TestHungryPage.h"
#import "DemoHunger.h"
#import "DemoCharge.h"
#import "AIInput.h"

@interface TestHungryPage ()<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UIButton *addBtn;
@property (weak, nonatomic) IBOutlet UIButton *subBtn;
@property (weak, nonatomic) IBOutlet UIButton *eatStartBtn;
@property (weak, nonatomic) IBOutlet UIButton *eatStopBtn;
@property (weak, nonatomic) IBOutlet UIButton *confirmBtn;
@property (weak, nonatomic) IBOutlet UITextField *tf;
@property (weak, nonatomic) IBOutlet UIButton *canceBtn;
@property (weak, nonatomic) IBOutlet UISlider *hungerLevelSlider;
@property (weak, nonatomic) IBOutlet UILabel *hungerLevelLab;
@property (weak, nonatomic) IBOutlet UIButton *thinkStatusBtn;
@property (weak, nonatomic) IBOutlet UIButton *mainThreadStatusBtn;
@property (weak, nonatomic) IBOutlet UITextField *logCountTF;

@end

@implementation TestHungryPage

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initView];
    [self initDisplay];
}

-(void) initView{
    //1,tf
    self.tf.delegate = self;
    [self.tf setReturnKeyType:UIReturnKeyGo];
    
    //2,hungerLevelLab
    [self.hungerLevelLab setText:STRFORMAT(@"%.2f",self.hungerLevelSlider.value)];
    [self.hungerLevelLab setTextColor:self.hungerLevelSlider.value > 0.7 ? [UIColor greenColor] : [UIColor redColor]];
    
    //3,mainThreadStatusBtn
    [self.mainThreadStatusBtn.layer setCornerRadius:3];
    [self.mainThreadStatusBtn.layer setMasksToBounds:true];
    [self.mainThreadStatusBtn.layer setBorderColor:[UIColor grayColor].CGColor];
    [self.mainThreadStatusBtn.layer setBorderWidth:1];
    
    //4,thinkStatusBtn
    [self.thinkStatusBtn.layer setCornerRadius:3];
    [self.thinkStatusBtn.layer setMasksToBounds:true];
    [self.thinkStatusBtn.layer setBorderColor:[UIColor grayColor].CGColor];
    [self.thinkStatusBtn.layer setBorderWidth:1];
}

-(void) initDisplay{
    //1,Observer
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationThinkBusyChanged) name:ObsKey_ThinkBusy object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationMainThreadBusyChanged) name:ObsKey_MainThreadBusy object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationHungerLevelChanged) name:ObsKey_HungerLevelChanged object:nil];
    
    //2,thinkStatusBtn
    [self.thinkStatusBtn setBackgroundColor:[UIColor greenColor]];
    
    //3,mainThreadStatusBtn
    [self.mainThreadStatusBtn setBackgroundColor:[UIColor greenColor]];
}

-(void) refreshDisplay_HungerLevelLab{
    NSString *value = STRFORMAT(@"%.3f",self.hungerLevelSlider.value);
    [self.hungerLevelLab setText:value];
    [self.hungerLevelLab setTextColor:self.hungerLevelSlider.value > 0.7 ? [UIColor greenColor] : [UIColor redColor]];
}

/**
 *  MARK:--------------------onclick--------------------
 */
- (IBAction)addBtnOnClick:(id)sender {
    [[[DemoCharge alloc] init] commit:HungerState_Charging];
}

- (IBAction)subBtnOnClick:(id)sender {
    [[[DemoCharge alloc] init] commit:HungerState_Unplugged];
}

- (IBAction)eatStartBtnOnClick:(id)sender {
    [[[DemoCharge alloc] init] commit:HungerState_Charging];
}

- (IBAction)eatStopBtnOnClick:(id)sender {
    [[[DemoCharge alloc] init] commit:HungerState_Unplugged];
}

- (IBAction)confirmBtnOnClick:(id)sender {
    if (STRISOK(self.tf.text)) {
        [theInput commitText:self.tf.text];
        self.tf.text = nil;
    }
}

- (IBAction)canceBtnOnClick:(id)sender {
    [self.tf resignFirstResponder];
    self.tf.text = nil;
}

- (IBAction)hungerLevelSliderValueChanged:(id)sender {
    [[[DemoHunger alloc] init] commit:self.hungerLevelSlider.value];
}

- (IBAction)thinkBtnOnClick:(id)sender {
    
}

- (IBAction)mainThreadStatusBtnOnClick:(id)sender {
    
}

- (IBAction)awarenessLogBtnOnClick:(id)sender {
    NSInteger count = [STRTOOK(self.logCountTF.text) integerValue];
    NSMutableArray *arr = [AIAwarenessStore searchWhere:nil count:count];
    for (AIAwarenessModel *aw in ARRTOOK(arr)) {
        AIObject *content = [aw.awarenessP content];
        [content print];
    }
}

/**
 *  MARK:--------------------method--------------------
 */
-(void) notificationThinkBusyChanged {
    [self.thinkStatusBtn setBackgroundColor:[UIColor greenColor]];
}

-(void) notificationMainThreadBusyChanged {
    [self.mainThreadStatusBtn setBackgroundColor:[UIColor greenColor]];
}

-(void) notificationHungerLevelChanged {
    [self refreshDisplay_HungerLevelLab];
}

/**
 *  MARK:--------------------UITextFieldDelegate--------------------
 */
- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [self confirmBtnOnClick:self.confirmBtn];
    return true;
}

-(void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
