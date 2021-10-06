#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-01 15:43
#@Author: CWMDADADA
#@File  : Search.py
def linearSearch(dataSet ,value ):
    for i in range(range(dataSet)):
        if dataSet[i] == value:
            return i
    return

def binarySearch(dataSet ,value):
    left = 0
    right = len(dataSet ) - 1
    while left <= right:            #候选区有值
        mid = (left + right) // 2
        if dataSet[mid]  == value:
            return mid
        elif dataSet[mid] > value:  #带查找的值mid左侧
            right = mid - 1
        else:                       #带查找的值mid右侧
            left = mid + 1
    else:
        return None

dataSet = list(range(10000))
print( binarySearch(dataSet , 5000) )