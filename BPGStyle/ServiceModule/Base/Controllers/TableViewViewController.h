//
//  TableViewViewController.h
//  BPGStyle
//
//  Created by baipeng on 2017/11/28.
//  Copyright © 2017年 BPG. All rights reserved.
//

#import "BaseViewController.h"

@interface TableViewViewController : BaseViewController<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UITableView *tableView;

- (void)initagainTableView;
- (void)registerCells;


@end
