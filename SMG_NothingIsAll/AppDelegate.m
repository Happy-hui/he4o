//
//  AppDelegate.m
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/4/7.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import "AppDelegate.h"
#import "StudyViewController.h"
#import "AINet.h"
#import "NSObject+Extension.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //1. Path
    NSArray * paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    NSLog(@"\n______________________________________\n\n%@\n______________________________________\n\n",paths[0]);
    
    //2. 初始化UI
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    StudyViewController *page = [[StudyViewController alloc] init];
    UINavigationController *naviC = [[UINavigationController alloc] initWithRootViewController:page];
    [self.window setRootViewController:naviC];
    [self.window makeKeyAndVisible];
    
    SEL runSEL = NSSelectorFromString(@"run:");
    SEL staticRunSEL = NSSelectorFromString(@"staticRun:");
    [self invocationMethodName:@"run:" withObjects:@[@(1)]];
    
    NSLog(@"____");
    
    
    
    [NSObject invocationMethodName:@"staticRun:" className:@"AppDelegate" withObjects:@[@(3)]];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {}

- (void)applicationDidEnterBackground:(UIApplication *)application {}

- (void)applicationWillEnterForeground:(UIApplication *)application {}

- (void)applicationDidBecomeActive:(UIApplication *)application {}

- (void)applicationWillTerminate:(UIApplication *)application {}

/**
 *  MARK:--------------------method--------------------
 */
-(UIViewController*) getTopDisplayViewController{
    UINavigationController *navC = (UINavigationController*)[self.window rootViewController];
    
    NSArray *controllers = navC.viewControllers;
    UIViewController *controller = [controllers lastObject];
    return controller;
}

+(void) staticRun:(NSNumber*)param{
    NSLog(@"staticRun>>%@",param);
}

-(void) run:(NSNumber*)param{
    NSLog(@"run>>%@",param);
}

@end
