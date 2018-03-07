//
//  BaseNavigationController.m
//  BPGStyle
//
//  Created by baipeng on 2017/11/28.
//  Copyright © 2017年 BPG. All rights reserved.
//

#import "BaseNavigationController.h"

@interface BaseNavigationController ()

@end

@implementation BaseNavigationController
+ (void)initialize
{
    // 设置导航栏的主题
    UINavigationBar *bar = [UINavigationBar appearance];
    [bar setTintColor:kColorWithHex(323232)];//字体颜色
    [bar setTitleTextAttributes:@{NSFontAttributeName : KScalefont(20)}];
    [bar setBarTintColor:kRGBAColor(252, 203, 38, 1)];//背景

}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated
{
    if (self.childViewControllers.count) {// 隐藏导航栏

        UIButton *button = [[UIButton alloc] init];
        [button setImage:[UIImage imageNamed:@"back_9x16"] forState:UIControlStateNormal];
        [button setImage:[UIImage imageNamed:@"back_9x16"] forState:UIControlStateHighlighted];
        button.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
        [button setTitle:@" 返回" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor redColor] forState:UIControlStateHighlighted];
        [button addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
        button.bounds = CGRectMake(0, 0, 70, 30);
        button.contentEdgeInsets = UIEdgeInsetsMake(0,  0, 0, 0);
        [button sizeToFit];
        button.titleLabel.font = [UIFont systemFontOfSize:15];
        viewController.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:button];


        // 如果自定义返回按钮后, 滑动返回可能失效, 需要添加下面的代码
        __weak typeof(viewController)Weakself = viewController;
        self.interactivePopGestureRecognizer.delegate = (id)Weakself;

        // 2.隐藏底部TabBar导航条
        viewController.hidesBottomBarWhenPushed = YES;
    }

    [super pushViewController:viewController animated:animated];
}

- (void)back
{
    // 判断两种情况: push 和 present
    if ((self.presentedViewController || self.presentingViewController) && self.childViewControllers.count == 1) {
        [self dismissViewControllerAnimated:YES completion:nil];
    }else
        [self popViewControllerAnimated:YES];
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
