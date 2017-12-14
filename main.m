//
//  main.m
//  MKJToolKit
//
//  Created by Mark Lewis on 17-12-14.
//  Copyright (c) 2017年 Mark Lewis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MKJAlgorithms.h"
#include "SportsAchievementManager.h"
int main(int argc, const char * argv[])
{
    @autoreleasepool
    {
        // insert code here...
        NSLog(@"Hello, World!");
        
        [MKJToolKit selectionSortTestCase]; // OC调用OC++的类的方法 再调用C++文件中定义的函数
        
        SportsManagerRuns();
    }
    return 0;
}

