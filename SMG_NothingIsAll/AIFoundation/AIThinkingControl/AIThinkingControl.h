//
//  AIThinkingControl.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/11/12.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------思维控制器--------------------
 *  1. 主要负责思维 (前额叶) 功能;
 *  2. 次要负责分发激活等 (丘脑) 功能;
 */
@interface AIThinkingControl : NSObject

+(AIThinkingControl*) shareInstance;


/**
 *  MARK:--------------------流入input--------------------
 */
-(void) commitInput:(NSObject*)algsModel;


/**
 *  MARK:--------------------输出的日志入网(输入小脑)--------------------
 *  @param algsType  : 输出算法分区(目前仅有Output)
 *  @param dataSource    : 输出算法函数(如output_Text:)
 *  @param outputObj : 输出内容(如:饿死爹了)
 */
-(void) commitOutputLog:(NSString*)algsType dataSource:(NSString*)dataSource outputObj:(NSNumber*)outputObj;

@end
