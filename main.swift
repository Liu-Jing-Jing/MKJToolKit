//
//  main.swift
//  5-InsertionSort
//
//  Created by Mark on 2017/11/26.
//  Copyright © 2017年 Mark. All rights reserved.
//

import Foundation
protocol SortType{
    func sort(items: Array<Int>) -> Array<Int>
    func sort(items: Array<Double>) -> Array<Double>
    func sort(items: Array<String>) -> Array<String>
    func sort(items: Array<Student>) -> Array<Student>
}



func swap(a: inout Int, b: inout Int)
{
    let temp = a
    a = b
    b = temp
}
//随机数生成器函数
func createRandomMan(start: Int, end: Int) ->() ->Int! {
    //根据参数初始化可选值数组
    var nums = [Int]();
    for i in start...end{
        nums.append(i)
    }
    
    func randomMan() -> Int! {
        if !nums.isEmpty {
            //随机返回一个数，同时从数组里删除
            let index = Int(arc4random_uniform(UInt32(nums.count)))
            return nums.remove(at: index) // nums.removeAtIndex(index)
            
        }
        else {
            //所有值都随机完则返回nil
            return nil
        }
    }
    
    return randomMan
}


class SelectionSort: SortType
{
    func sort(items: Array<Int>) -> Array<Int>{
        print("Selection Sort")
        
        var list = items
        for i in 0..<list.count
        {
            print("第(\(i+1)轮选择,选择下标的范围是\(i)...\(list.count)")
            var minIndex = i
            
            for j in i+1..<list.count
            {
                if list[j] < list[minIndex]
                {
                    print("min \(list[j])  < \(list[minIndex])")
                    minIndex = j
                }
            }
            // 记得swap
            let temp = list[i]
            list[i] = list[minIndex]
            list[minIndex] = temp
            print("完成本轮结果为:\(list)\n")
        }
        return list
    }
    func sort(items: Array<Double>) -> Array<Double>{
        print("Selection Sort")
        
        var list = items
        for i in 0..<list.count
        {
            print("第(\(i+1)轮选择,选择下标的范围是\(i)...\(list.count)")
            var minIndex = i
            
            for j in i+1..<list.count
            {
                if list[j] < list[minIndex]
                {
                    print("min \(list[j])  < \(list[minIndex])")
                    minIndex = j
                }
            }
            // 记得swap
            let temp = list[i]
            list[i] = list[minIndex]
            list[minIndex] = temp
            print("完成本轮结果为:\(list)\n")
        }
        return list
    }
    
    func sort(items: Array<String>) -> Array<String>{
        print("Selection Sort")
        
        var list = items
        for i in 0..<list.count
        {
            print("第(\(i+1)轮选择,选择下标的范围是\(i)...\(list.count)")
            var minIndex = i
            
            for j in i+1..<list.count
            {
                if list[j] < list[minIndex]
                {
                    print("min \(list[j])  < \(list[minIndex])")
                    minIndex = j
                }
            }
            // 记得swap
            let temp = list[i]
            list[i] = list[minIndex]
            list[minIndex] = temp
            print("完成本轮结果为:\(list)\n")
        }
        return list
    }

    func sort(items: Array<Student>) -> Array<Student>{
        print("Selection Sort")
        
        var list = items
        for i in 0..<list.count
        {
            print("第(\(i+1)轮选择,选择下标的范围是\(i)...\(list.count)")
            var minIndex = i
            
            for j in i+1..<list.count
            {
                if list[j].compareTo(that: list[minIndex])<0
                {
                    print("min \(list[j])  < \(list[minIndex])")
                    minIndex = j
                }
            }
            // 记得swap
            let temp = list[i]
            list[i] = list[minIndex]
            list[minIndex] = temp
            print("完成本轮结果为:\(list)\n")
        }
        return list
    }
}

func testSort(sortObj: SortType, list: Array<Int>)
{
    
    let sortList  = sortObj.sort(items: list)
    print("\(sortList)\n\n")
}


func testSort(sortObj: SortType, list: Array<Double>)
{
    let sortList  = sortObj.sort(items: list)
    print("\(sortList)\n\n")
}


func testSort(sortObj: SortType, list: Array<String>)
{
    let sortList  = sortObj.sort(items: list)
    print("\(sortList)\n\n")
}

func testSort(sortObj: SortType, list: Array<Student>)
{
    let sortList  = sortObj.sort(items: list)
    print("\(sortList)\n\n")
}


// SortTestHelper {

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
func generateRandomArray(n: Int, rangeL: Int, rangeR: Int) -> (Array<Int>){
    
    assert(rangeL <= rangeR);
    
    var list: Array<Int> = []
    
    // srand(time(NULL));
    let random1 = createRandomMan(start: 0,end: (rangeR - rangeL) + rangeL)
    for _ in 0..<n
    {
        list.append(random1())
    }
    
    return list;
}


// 打印arr数组的所有内容
func printArray(list: Array<Int>)
{
    for i in 0..<list.count
    {
        print("\(list[i]) \n")
    }
}

// 测试Integer
// testSort(sortObj: SelectionSort(), list: generateRandomArray(n: 10, rangeL: 0, rangeR: 300))
testSort(sortObj: SelectionSort(), list:[0, 10, 3, 3, 0, 7, 8, 8, 1, 6, ])


// 测试Double
testSort(sortObj: SelectionSort(), list:[4.4, 3.3, 2.2, 1.1, 1.1, 0.5, 0.7])


// 测试String
testSort(sortObj: SelectionSort(), list:["D", "C", "B", "A"])

// 测试自定义的类 Student
var d: Array<Student> = [Student(name: "D",score: 90), Student(name: "C",score: 100), Student(name: "B",score: 95), Student(name: "A",score: 95)]
// testSort(sortObj: SelectionSort(), list: d)


