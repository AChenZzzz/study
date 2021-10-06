#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 16:29
#@Author: CWMDADADA
#@File  : CountSort.py

def countSort(dataSet , max_count = 100):
    count = [0 for _ in range(max_count+1)]
    for val in dataSet:
        count[val] += 1
    dataSet.clear()
    for ind, val in enumerate(count):
        for i in range(val):
            dataSet.append(ind)

import random
dataSet = [random.randint(0,100) for _ in  range(1000)]
print(dataSet)
countSort(dataSet)
print(dataSet)