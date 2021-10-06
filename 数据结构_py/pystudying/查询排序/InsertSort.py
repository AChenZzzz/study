#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 13:29
#@Author: CWMDADADA
#@File  : InsertSort.py
def insertSort(dataSet):
    for i in range(1, len(dataSet)):        #i 表示摸到的牌
        temp  = dataSet[i]
        j = i - 1                           #j 表示手里的牌
        while j >= 0 and dataSet[j] < temp:
            dataSet[j+1] = dataSet[j]
            j -= 1
        dataSet[j+1] = temp
    print(dataSet)