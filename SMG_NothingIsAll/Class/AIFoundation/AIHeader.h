//
//  AIHeader.h
//  SMG_NothingIsAll
//
//  Created by 贾  on 2017/5/21.
//  Copyright © 2017年 XiaoGang. All rights reserved.
//

#import "AIObject.h"
#import "AIString.h"
#import "AIChar.h"
#import "AIArray.h"

#import "AILogicModel.h"

#import "AIPointer.h"
#import "AILine.h"
#import "AILineStrong.h"
#import "AILineDampingStrategy.h"

#import "AIMindValueModel.h"
#import "AIExperienceModel.h"
#import "AIObjModel.h"

//封装AIStore层;用于各种数据的不同取数据方法;
#import "AIStoreBase.h"
#import "AIExperienceStore.h"
#import "AIMindValueStore.h"
#import "AILineStore.h"
#import "AIObjStore.h"

#import "AIMainThread.h"
#import "AINode.h"
#import "AIPort.h"
#import "AISqlPointer.h"
#import "AIKVPointer.h"
#import "NSObject+Extension.h"
#import "AINode.h"

/**
 *  MARK:--------------------数据检查--------------------
 */

//String
#define AISTRISOK(a) (a  && [a isKindOfClass:[AIString class]] && a.content && [a.content isKindOfClass:[NSArray class]] && a.content.count > 0)
#define AISTRTOOK(a) (a  && [a isKindOfClass:[AIString class]] ? a : [AIString newWithContent:@""])

//Array
#define AIARRISOK(a) (a  && [a isKindOfClass:[AIArray class]] && a.content && [a.content isKindOfClass:[NSArray class]] && a.content.count > 0)
#define AIARRTOOK(a) (a  && [a isKindOfClass:[AIArray class]]) ?  a : [AIArray initWithObjects:nil]
#define AIARR_INDEX(a,i) (a && [a isKindOfClass:[AIArray class]]) ?  [a objectAtIndex:i] : nil//数组取子防闪


/**
 *  MARK:--------------------快捷建对象--------------------
 */
//Char
#define AIMakeCharByStr(a) [AIChar newWithContentByString:a]
#define AIMakeChar(a) [AIChar newWithContent:a]

//String
#define AIMakeStr(a) [AIString newWithContent:a]
#define AISTRFORMAT(a, ...) [AIString newWithContent:[NSString stringWithFormat:a, ##__VA_ARGS__]]

//Array
#define AIMakeArr(a, ...) [AIArray initWithObjects:a, ##__VA_ARGS__,nil]
//#define AIMakeArr_Pointer(a, ...) [AIArray initWithObjects:a, ##__VA_ARGS__,nil]

//AILine
#define AIMakeLine(type,objs) [AILine newWithType:type aiObjs:objs]

