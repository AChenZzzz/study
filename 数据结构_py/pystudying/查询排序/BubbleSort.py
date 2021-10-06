#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-01 16:35
#@Author: CWMDADADA
#@File  : BubbleSort.py
import random

def bubbleSort(dataSet):
    for i in range(len(dataSet) - 1):
        exchange = False
        for j in range(len(dataSet) - i - 1):
            if dataSet[j] > dataSet[j+1]:
                dataSet[j] , dataSet[j+1] = dataSet[j+1], dataSet[j]
                exchange = True
        print(dataSet)
        if not exchange:
            return






dataSet = [random.randint(0,10000) for i in range(10)]
print(dataSet)
