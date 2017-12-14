//
//  MKJSelectionSort.m
//  MKJToolKit
//
//  Created by Mark on 2017/12/14.
//  Copyright © 2017年 Mark Lewis. All rights reserved.
//

#import "MKJSelectionSort.h"

@implementation MKJSelectionSort
+ (void)sort1:(int [])arr arrayLength:(int) n
{
    for(int i = 0 ; i < n ; i ++)
    {
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        //swap( arr[i] , arr[minIndex] );
    }
}

+ (void)sort1TestCase
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    printf("排序前的数组\n");
    for( int i = 0 ; i < 10 ; i ++ ) printf("%d ", a[i]);
    
    printf("\n排序好的数组\n");
    [MKJSelectionSort sort1:a arrayLength:10];
    for( int i = 0 ; i < 10 ; i ++ ) printf("%d ", a[i]);
    
    printf("\nOK");
}
@end
