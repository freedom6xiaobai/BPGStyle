//
//  KHeaderConfig.h
//  BPGStyle
//
//  Created by baipeng on 2017/11/28.
//  Copyright © 2017年 BPG. All rights reserved.
//

#ifndef KHeaderConfig_h
#define KHeaderConfig_h

/** 第一次登录 */
#define KisRootingNewFirstLoginKey           @"KisRootingNewFirstLogin"
//判断是真机还是模拟器
#if TARGET_OS_IPHONE//真机
#endif

#if TARGET_IPHONE_SIMULATOR //模拟器
#endif



//开发的时候打印，但是发布的时候不打印的NSLog
#ifdef DEBUG
#define NSLog(fmt, ...) NSLog((@"%s [第%d行] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define MyNSLog(FORMAT, ...) fprintf(stderr,"[%s]:[line %d行] %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(...)
#define MyNSLog(FORMAT, ...) nil
#endif




// 快速实例
#define KObject(Class) [[Class alloc] init];
// 快速初始化xib
#define KNibNameXib(Class)  [[[NSBundle mainBundle] loadNibNamed:(Class) owner:nil options:nil] lastObject]
//字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == NULL || str == nil || [[str stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceCharacterSet]] length] == 0 || [str length] < 1 ? YES : NO )
//数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

//字符串@
#define KNSStringVaule(string) [NSString stringWithFormat:@"%@",string]
//字符串d
#define KIntegerVaule(integer) [NSString stringWithFormat:@"%ld",(long)integer]



//一些缩写
#define kApplication        [UIApplication sharedApplication]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kAppDelegate        [UIApplication sharedApplication].delegate
#define kNotificationCenter [NSNotificationCenter defaultCenter]
/** 数据存储*/
#define kUserDefaults       [NSUserDefaults standardUserDefaults]
/** 机器码 */
#define KAppdeviceToken             @"AppDeviceToken"
#define KDefaultsAppdeviceToken    [kUserDefaults objectForKey:KAppdeviceToken]





//获取屏幕宽度与高度
#define kScreenWidth \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
#define kScreenHeight \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
#define kScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)


//判断当前是否为横屏
#define isHorScreen                     kScreenWidth > kScreenHeight

/** 设计图模型宽 这里以6s */
#define BPGIsPhoneWidth     375.0
#define BPGIsPhoneHeight    667.0
/** 尺寸缩放 */
#define KScale(f)           (f) *  (isHorScreen ? kScreenHeight : kScreenWidth)/BPGIsPhoneWidth
/** 字体缩放，依据iphone6 */
#define KScalefont(f)       [UIFont systemFontOfSize:KScale(f)]
/**  非适配字体大小 */
#define KFont(f)            [UIFont systemFontOfSize:f]

/**  导航栏高度 */
#define kNavBarHeight                   self.navigationController.navigationBar.frame.size.height
/** 标签栏高度 */
#define kStatusBarHeight                [[UIApplication sharedApplication] statusBarFrame].size.height
/**  导航栏和标签栏高度 */
#define KNavigationBarHeight            (kStatusBarHeight + kNavBarHeight)
/** 底部TabBar的高度 */
#define kTabBarHeight                ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)


/** 多线程GCD*/
#define kGlobalGCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define kMainGCD(block) dispatch_async(dispatch_get_main_queue(),block)
#define kTimeGCD(delay,block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC)), dispatch_get_main_queue(),block)


//APP版本号
#define kAppVersion         [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
//获取当前语言
#define kCurrentLanguage    ([[NSLocale preferredLanguages] objectAtIndex:0])
//判断是否为iPhone
#define kISiPhone           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define kISiPad             (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)




//获取沙盒Document路径
#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒temp路径
#define kTempPath NSTemporaryDirectory()
//获取沙盒Cache路径
#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//颜色
#define kRGBColor(r, g, b)      [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBAColor(r, g, b, a)  [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define KRGBRandomColor         [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

#define KColorHex(rgbValue)     [UIColor colorWithHexString:rgbValue]
#define kColorWithHex(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]

#define KWhiteColor [UIColor whiteColor]
#define KBlackColor [UIColor blackColor]
#define KClearColor [UIColor clearColor]
//背景
#define KProductBackGray        kRGBColor(248, 248, 248)
/** 地址灰色字体 */
#define KBackGray               kRGBColor(146, 146, 146)

//弱引用/强引用
#define kWeakSelf(type)     __weak typeof(type) weak##type = type
#define kStrongSelf(type)   __strong typeof(type) strong##type = weak##type


/** 系统版本号*/
#define kSystemVersion  [[UIDevice currentDevice] systemVersion]
// iPhone4
#define IS_IPhone4  (([UIScreen mainScreen].bounds.size.height == 480)? YES : NO)
//iPhone5 SE
#define IS_IPhone5  (([UIScreen mainScreen].bounds.size.height == 568)? YES : NO)
//iPhone6 6s 7 8
#define IS_IPhone6  (([UIScreen mainScreen].bounds.size.height == 667)? YES : NO)
//iPhone6p 7p 8p
#define IS_IPhone6p (([UIScreen mainScreen].bounds.size.height == 736)? YES : NO)
//iPhoneX
#define IS_IPhoneX  (([UIScreen mainScreen].bounds.size.height == 812)? YES : NO)
#define kDeviceIsiPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

/* 屏幕有关 */
#define iPone4      ([UIScreen mainScreen].bounds.size.height == 480)
#define iPone5      ([UIScreen mainScreen].bounds.size.height == 568)
#define iPone6      ([UIScreen mainScreen].bounds.size.height == 667)
#define iPone6p     ([UIScreen mainScreen].bounds.size.height == 736)
#define iPoneX      ([UIScreen mainScreen].bounds.size.height == 812)



/** 控制器释放 */
#define VCromClassDealloc          NSLog(@"---will class %@",NSStringFromClass([self class]))
/**警告框 */
#define SHOWALERT(m) \
{\
UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:m delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil];\
[alert show]; \
}\


//TODO: 其他宏定义
/** Bundle 资源包路径 */
#define BPGBundleSubPath(name,path)     [[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent: [NSString stringWithFormat:@"%@.bundle",name]]stringByAppendingPathComponent:[NSString stringWithFormat:@"%@/",path]]




#endif /* KHeaderConfig_h */
