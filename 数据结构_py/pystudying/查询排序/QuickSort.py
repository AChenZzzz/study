#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 13:29
#@Author: CWMDADADA
#@File  : QuickSort.py

def partition(dataSet ,left , right):
    temp = dataSet[left]
    while left < right:
        while left <right and dataSet[right] >= temp:   #从右边找比temp小的数
            right -= 1                                  #往左走一步
        dataSet[left] = dataSet[right]                  #右边的值写到左边的空位
        while left <right and dataSet[left] <= temp:
            left += 1
        dataSet[right] = dataSet[left]
    dataSet[left] = temp                                #temp归位
    return  left

def quickSort(dataSet , left, right):
    if left < right:                                    #至少两个元素
        mid = partition(dataSet , left, right)
        quickSort(dataSet , left, mid - 1)
        quickSort(dataSet , mid + 1, right)
