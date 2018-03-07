//
//  TabBarViewController.m
//  BPGStyle
//
//  Created by baipeng on 2017/11/28.
//  Copyright © 2017年 BPG. All rights reserved.
//

#import "TabBarViewController.h"
#import "BPTmpViewController.h"
#import "MineViewController.h"

@interface TabBarViewController ()<UITabBarControllerDelegate>

@end

@implementation TabBarViewController
+ (void)initialize
{
//    [[UITabBar appearance] setBackgroundImage:[UIImage imageNamed:@"tabbar-light"]];//背景色

    // 获取TabBarItem的appearence
    UITabBarItem *appearance = [UITabBarItem appearance];
    // 正常状态
    NSDictionary *normalDict = @{
                                 NSForegroundColorAttributeName: kRGBColor(66, 66, 66),
                                 NSFontAttributeName:KScalefont(12)
                                 };
    [appearance setTitleTextAttributes:normalDict forState:UIControlStateNormal];

    // 选中状态
    NSDictionary *selectedDict = @{
                                   NSForegroundColorAttributeName:kRGBColor(1, 1, 1),
                                   NSFontAttributeName:KScalefont(12)
                                   };
    [appearance setTitleTextAttributes:selectedDict forState:UIControlStateSelected];

    //隐藏阴影线
    [[UITabBar appearance] setShadowImage:[[UIImage alloc] init]];
    [UITabBar appearance].barTintColor=[UIColor whiteColor];//背景颜色为红色

}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    // 初始化所有的子控制器
    [self setupChildViewControllers];


}
/**
 * 初始化所有的子控制器
 */
- (void)setupChildViewControllers
{
    BPTmpViewController *selorList = [[BPTmpViewController alloc] init];
    [self setupOneChildViewController:selorList title:@"咨询" image:@"tabbar_icon_reader_normal" selectedImage:@"tabbar_icon_reader_highlight"];



    MineViewController *mine = [[MineViewController alloc] init];
    [self setupOneChildViewController:mine title:@"我的" image:@"tabbar_icon_found_normal" selectedImage:@"tabbar_icon_found_highlight"];


}



- (void)setupOneChildViewController:(UIViewController *)vc title:(NSString *)title image:(NSString *)image selectedImage:(NSString *)selectedImage
{
    vc.tabBarItem.title = title;
    vc.title = title;
    UIImage *musicImage = [UIImage imageNamed:image];
    UIImage *musicImageSel = [UIImage imageNamed:selectedImage];
    musicImage = [musicImage imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    musicImageSel = [musicImageSel imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    vc.tabBarItem.image =  musicImage;
    vc.tabBarItem.selectedImage =musicImageSel;
    [self addChildViewController:[[BaseNavigationController alloc] initWithRootViewController:vc]];
}

#pragma mark - UITabBarControllerDelegate
- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item {
    UIView *tabBarButton = [item valueForKey:@"_view"];
    if ([tabBarButton isKindOfClass:NSClassFromString(@"UITabBarButton")]) {
        CABasicAnimation *imgAnimation = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
        imgAnimation.duration = 0.25;
        imgAnimation.fromValue = @(0.2);
        imgAnimation.toValue = @(1.3);
        imgAnimation.autoreverses = YES;
        UIImageView *img = [tabBarButton valueForKey:@"_info"];
        [img.layer addAnimation:imgAnimation forKey:nil];
    }
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
