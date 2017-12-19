//
//  Student.swift
//  5-InsertionSort
//
//  Created by Mark on 2017/11/26.
//  Copyright © 2017年 Mark. All rights reserved.
//

import Cocoa
class Student: NSObject{
    
    var name: String
    var score: Int
    
    init(name: String, score: Int)
    {
        self.name = name
        self.score = score
    }
    func Student(name: String, score:Int){
        self.name = name
        self.score = score
    }
    
    // 定义Student的compareTo函数
    // 如果分数相等，则按照名字的字母序排序
    // 如果分数不等，则分数高的靠前
    func compareTo(that: Student) -> Int
    {
        if( self.score < that.score )
        {
            return -1
        }
        else if( self.score > that.score )
        {
            return 1
        }
        else // this.score == that.score
        {
            return (self.name.compare(that.name)).rawValue
        }
    }
    
    // 定义Student实例的打印输出方式
    
    func toString() -> String
    {
        return "Student: \(self.name) \(self.score)"
    }
}
