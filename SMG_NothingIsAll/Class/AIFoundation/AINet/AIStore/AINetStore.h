//
//  AINetStore.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/9/30.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------AINetStore存储器--------------------
 *  1. 自动进行AIPointer,AILine,AIPort,存储等操作;
 */
@interface AINetStore : NSObject

+(AINetStore*) sharedInstance;

/**
 *  MARK:--------------------存obj到神经网络--------------------
 */
-(BOOL) setObjectWithNetNode:(AINode*)node;                         //存神经网络_节点
-(BOOL) setObjectWithNetData:(AIObject*)data;                       //存神经网络_数据
-(BOOL) setObject:(AIObject*)obj folderName:(NSString*)folderName pointerId:(NSInteger)pointerId;


/**
 *  MARK:--------------------根据节点指针取节点--------------------
 */
-(/*AIObject**/id) objectForKvPointer:(AIKVPointer*)kvPointer;
-(BOOL) objectFor:(id)obj folderName:(NSString*)folderName;

@end



@interface AINetStore (Memory)
@end
