//
//  AIMindValue.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/12/10.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  MARK:--------------------mindValue--------------------
 *  MindType_Hunger     =   0,//饥饿
 *  MindType_Happy      =   4,//开心
 */
@interface AIMindValue : NSObject

-(id) initFromModel_RuleType:(MVRuleType)ruleType duration:(CGFloat)duration downType:(MVDownCurveType)downType;
-(id) initFromInput_RuleType:(MVRuleType)ruleType duration:(CGFloat)duration upType:(MVUpCurveType)upType inputValue:(CGFloat)inputValue downType:(MVDownCurveType)downType;

-(void) requestRule:(void(^)(CGFloat value))success failure:(void(^)())failure;


/**
 *  MARK:--------------------持续性处理--------------------
 */
//-(void) asdfasdf;



/**
 *  MARK:--------------------Method_规则部分--------------------
 */
//-(void) asdfasdf;

@end



/**
 *  MARK:--------------------曲线算法--------------------
 */
@interface AIMindValueCurve :NSObject

+(CGFloat) getValueWithType:(MVDownCurveType)downType progress:(CGFloat)progress;

@end
