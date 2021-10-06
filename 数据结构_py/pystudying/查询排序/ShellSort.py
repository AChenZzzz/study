#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 13:39
#@Author: CWMDADADA
#@File  : ShellSort.py

def insertSortGap(dataSet , gap):
    for i in range(1, len(dataSet)):        #i 表示摸到的牌
        temp  = dataSet[i]
        j = i - gap                         #j 表示手里的牌
        while j >= 0 and dataSet[j] < temp:
            dataSet[j+gap] = dataSet[j]
            j -= gap
        dataSet[j+gap] = temp
    print(dataSet)

def shellSort(dataSet ):
    d = len(dataSet)//2
    while d >= 1:
        insertSortGap(dataSet , d )
        d //= 2

dataSet = list(range(1000))
import random
random.shuffle(dataSet)
shellSort(dataSet)
print(dataSet)