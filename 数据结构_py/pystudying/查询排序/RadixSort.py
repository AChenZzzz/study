#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 18:11
#@Author: CWMDADADA
#@File  : RadixSort.py

def radixSort(dataSet ):
    max_num = max(dataSet)
    it = 0
    while 10 ** it <= max_num:
        buckets = [[] for _ in range(10)]
        for var in dataSet:
            digit = (var // 10 ** it) % 10
            buckets[digit].append(var)
        #分桶完成
        dataSet.clear()
        for buc in buckets:
            dataSet.extend(buc)
        #重新写回dataSet
        it += 1                     #位数分桶

import random
Li = list(range(1000))

random.shuffle(Li)
print(Li)
radixSort(Li)
print(Li)