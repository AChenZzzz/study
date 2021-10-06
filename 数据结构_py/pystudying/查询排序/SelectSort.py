#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 13:28
#@Author: CWMDADADA
#@File  : SelectSort.py

def selectSort(dataSet):
    for i in range(len(dataSet) - 1):
        min_loc = i
        for j in range(i, len(dataSet)):
            if dataSet[j] < dataSet[min_loc]:
                min_loc = j
            dataSet[i],dataSet[min_loc] = dataSet[min_loc],dataSet[i]
            print(dataSet)