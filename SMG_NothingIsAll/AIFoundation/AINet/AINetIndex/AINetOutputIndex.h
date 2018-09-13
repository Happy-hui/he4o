//
//  AINetOutputIndex.h
//  SMG_NothingIsAll
//
//  Created by iMac on 2018/7/24.
//  Copyright © 2018年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  MARK:--------------------微信息Output索引 (小脑)--------------------
 *  1. 装箱 (用于将outLog信息进行装索引)
 *  AIOutputKVPointer *output_p = [theNet getOutputIndex:algsType dataTo:dataTo outputObj:outputObj];
 *
 *  2. 记录可输出reference (用于将指针,索引到引用序列)
 *  [theNet setNetNodePointerToOutputReference:output_p algsType:algsType dataTo:dataTo difStrong:1];
 */
@class AIPointer,AIOutputKVPointer;
@interface AINetOutputIndex : NSObject


/**
 *  MARK:--------------------根据data直接查找output_p--------------------
 *  1. 如果未找到,则创建一个,并返回;
 */
-(AIOutputKVPointer*) getDataPointerWithData:(NSNumber*)data algsType:(NSString*)algsType dataTo:(NSString*)dataTo ;
-(void) setIndexReference:(AIOutputKVPointer*)indexPointer target_p:(AIOutputKVPointer*)target_p difValue:(int)difValue;
-(NSArray*) getIndexReference:(AIOutputKVPointer*)indexPointer limit:(NSInteger)limit;

@end


/**
 *  MARK:--------------------内存DataSortModel (一组index)--------------------
 *  1. 排序是根据"值"大小排;
 *  2. pointerIds里存的是"值的指针"的pointerId;
 */
@interface AINetOutputIndexModel : NSObject <NSCoding>

@property (strong,nonatomic) NSMutableArray *pointerIds;
@property (strong,nonatomic) NSString *algsType;
@property (strong,nonatomic) NSString *dataTo;

@end
