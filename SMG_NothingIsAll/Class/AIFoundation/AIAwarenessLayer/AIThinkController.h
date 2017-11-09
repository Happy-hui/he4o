//
//  AIThinkController.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/11/9.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

//MARK:===============================================================
//MARK:                     < ThinkController的Lift Cycle >
//MARK:===============================================================
@protocol IThinkController <NSObject>

/**
 *  MARK:--------------------初始化任务--------------------
 *  由`意识控制器`提交过来的任务只是:
 *  1. 任务源:(神经网络的数据)
 *  2. 任务目标:(一个mindValue方向 | 其它)
 *  3.
 */
-(id) initWithTask:(id)task;


/**
 *  MARK:--------------------初始化运行--------------------
 */
-(void) initRun;


/**
 *  MARK:--------------------事务--------------------
 */
-(void) think;


/**
 *  MARK:--------------------想像力--------------------
 */
-(void) imagination;


@end




//MARK:===============================================================
//MARK:                     < 思维控制器 >
//MARK:===============================================================
@interface AIThinkController : NSObject <IThinkController>

@end
