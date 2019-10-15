//
//  BHFaceController.h
//
//
//  Created by DF-Mac on 17/4/28.
//  Copyright © 2017年 BoomHope. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HRFaceBaseMacro.h"
#import "BHFaceController.h"
#import <BHFaceDetector/BHFaceEnumType.h>
#import <BHFaceDetector/STLivenessDetectorDelegate.h>

typedef NS_ENUM(int, livingResultsType) {

    unknown,
    
    checkYES,
    
    checkNO,
    
    checkCancel,
    
};

typedef void(^AliveFace)(NSString *facePath,UIImage *faceImage,NSString *videoPath,livingResultsType livingResult);


@interface BHFaceController : UIViewController

// 眨眼,张嘴,摇头,点头  对应  1, 2, 3, 4
// 设置动作序列 注意动作序列必须有眨眼
@property (nonatomic, copy)NSArray *aliveTypeArr;

//设置语音提示默认是否开启 , 不设置时默认为YES即开启.
@property (nonatomic , assign) BOOL bVoicePrompt;

// 每个动作测试时间
@property (nonatomic , assign) int movementTestTime;

//录制时间
@property (nonatomic , assign) int recordTime;

// 回调数据
-(void)backData:(AliveFace)backData;

@end
