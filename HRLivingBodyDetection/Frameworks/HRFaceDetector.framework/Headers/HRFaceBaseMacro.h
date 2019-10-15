//
//  BaseMacro.h
//  HRFaceSign
//
//  Created by 吕清毅 on 2018/11/6.
//  Copyright © 2018年 lqy. All rights reserved.
//

#ifndef HRFaceBaseMacro_h
#define HRFaceBaseMacro_h

/*
 *ios系统版本
 */
#define ios11x [[[UIDevice currentDevice] systemVersion] floatValue] >=11.0f
#define LessIos11 [[[UIDevice currentDevice] systemVersion] floatValue] < 11.0f
#define ios10x [[[UIDevice currentDevice] systemVersion] floatValue] >=10.0f
#define ios9x [[[UIDevice currentDevice] systemVersion] floatValue] >=9.0f

/**
 *  屏幕大小
 */
#define SCREENWIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENHEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREENBOUNDS [UIScreen mainScreen].bounds

#define iphone4x_3_5 ([UIScreen mainScreen].bounds.size.height==480.0f)
#define iphone5x_4_0 ([UIScreen mainScreen].bounds.size.height==568.0f)
#define iphone6_4_7 ([UIScreen mainScreen].bounds.size.height==667.0f)
#define iphone6Plus_5_5 ([UIScreen mainScreen].bounds.size.height==736.0f || [UIScreen mainScreen].bounds.size.width==414.0f)
#define iPhone_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone_XS (([[[UIApplication sharedApplication] delegate]window].safeAreaInsets.bottom >0.0)? YES : NO)

#define TabBarHeight 49
#define TopBarHeight (iPhone_X?88:64)
#define TopBarHeight_xs (iPhone_XS?88:64)

#define NavigationBarHeight 44

#define TopStatusHeight (iPhone_X?24:0)
#define TopStatusHeight_xs (iPhone_XS?24:0)

#define BottomHeight (iPhone_X?34:0)
#define BottomHeight_xs (iPhone_XS?34:0)

#define leftPadding 40

/* 全局屏幕比例 */
#define AutoSizeScaleX SCRESNWIDTH/375
/* 按X轴相对于4.7寸屏幕的比例缩放尺寸 */
#define SizeX(size) AutoSizeScaleX*size

/*
 *USERDEFAULTS设置
 *本地存储键值
 *get 取值
 *save 存值
 */
#define USER_DEFAULTS_GET(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
#define USER_DEFAULTS_SAVE(value, key) [[NSUserDefaults standardUserDefaults] setObject:value forKey:key];\
[[NSUserDefaults standardUserDefaults] synchronize]

/*
 *弱引用，防止循环引用
 */
#define MYSELF(weakSelf) __weak __typeof(&*self) weakSelf = self

#define APP_DELEGATE ((AppDelegate *)[[UIApplication sharedApplication] delegate])
/**
 * 判断注册登录字符长度
 */
//姓名长度
#define TC_NameLength 12
//手机号码长度
#define TC_TelLength 11
//密码长度
#define TC_PwdMaxLength 20
#define TC_PwdMinLength 8
//验证码长度
#define TC_CodeMaxLength 4

/**
 发送通知
 **/
#define KPostNotification(name,obj) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj];
/**
 接受通知
 **/
#define KAddNotification(key,name)  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(key:) name:name object:nil];

/**
 通知的名称
 **/
#define SessionID   @"SessionID"
#define LoginStatue   @"LoginStatue"
#define ImageRefresh   @"ImageRefresh"
#define NoticeRefresh @"NoticeRefresh" //添加公告刷新通知
#define RefreshStatue  @"RefreshStatue" //人机面签
#define BankName  @"BankName"
#define BankCode  @"BankCode"
/**
 * 字体
 */
#define FontWithSize(s)  [[[UIDevice currentDevice]systemVersion] floatValue] >= 9.0?[UIFont fontWithName:@"PingFangSC-Regular" size:s]:[UIFont fontWithName:@"Helvetica" size:s]
#define FontSemiboldSize(s)  [[[UIDevice currentDevice]systemVersion] floatValue] >= 9.0?[UIFont fontWithName:@"PingFangSC-Semibold" size:s]:[UIFont fontWithName:@"Helvetica" size:s]

/**
 * 粗体
 */
#define FontMediumWithSize(s) [[[UIDevice currentDevice]systemVersion] floatValue] >= 9.0?[UIFont fontWithName:@"PingFangSC-Medium" size:s]:[UIFont fontWithName:@"Helvetica" size:s]

/**
 *  颜色
 */
#define  UIColorFromHex(s) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >>8))/255.0 blue:((s & 0xFF))/255.0 alpha:1.0]

#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

#define  HexWithAlpha(s,a) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s & 0xFF00) >>8))/255.0 blue:((s & 0xFF))/255.0 alpha:a];

#define BlackTextColor  RGBACOLOR(66,66,66,1)
#define GrayTextColor   RGBACOLOR(248,248,248,1)
#define BtnBgColor      RGBACOLOR(239,208,83,1)


#define MainCharColor  UIColorFromHex(0xd0d0d2)
#define TotalWhite     [UIColor whiteColor]
#define titleColor     UIColorFromHex(0x424242)
#define BlueColor      UIColorFromHex(0x4F5BC4)
#define lineColor      UIColorFromHex(0xF1F1F1)
#define ClearColor     [UIColor clearColor]
#define ErrorColor     UIColorFromHex(0xE54C4C)


/**
 *导航背景颜色
 */
#define NavBgColor  RGBACOLOR(255,255,255,1)
#define WhiteTextColor  RGBACOLOR(255,255,255,1)


/**
 *  HUD展示时间
 */
#define HUDTime 1

/**
 *  判断是否是空字符串 非空字符串 ＝ yes
 *
 *  @param string
 *
 *  @return
 */

#define  NOEmptyStr(string)  [string isKindOfClass:[NSNull class]] || string == nil || [string length] < 1 || [string isEqualToString:@"(null)"] || [string isEqualToString:@"<null>"] || [[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0 ? NO : YES

/**
 *  判断是否是空字符串 空字符串 = yes
 *
 *  @param string
 *
 *  @return
 */
#define  IsEmptyStr(string) ([string isKindOfClass:[NSNull class]] || string == nil || [string length] < 1 || [string isEqualToString:@"(null)"] || [string isEqualToString:@"<null>"] || [[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0)


/**
 *  APP 名称
 */
#define APP_NAME [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

/**
 *  APP Build版本号
 */
#define APP_BUILD [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

/**
 *  APP 版本号
 */
#define APP_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/**
 *  APP BundleID
 */
#define APP_BUNDLEID [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"]


#endif /* BaseMacro_h */
