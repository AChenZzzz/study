#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 16:58
#@Author: CWMDADADA
#@File  : BucketSort.py
def bucketSort(dataSet , n = 100 ,max_num = 10000):
    buckets = [[] for _ in range(n)]
    #创建桶
    for var in dataSet:
        i = min( var // (max_num // n ), n - 1 )
        buckets[i].append(var)
    #i 表示var放到几号桶里
        for j in range(len(buckets[i]) - 1, 1, -1):
            if buckets[i][j] < buckets[i][j - 1]:
                buckets[i][j], buckets[i][j - 1] = buckets[i][j - 1], buckets[i][j]
            else:
                break
    # 保持桶内的顺序
    sortedList = []
    for buc in buckets:
        sortedList.extend(buc)
    return sortedList

import random
Li = [random.randint(0,10000) for i in range(10000)]
List = bucketSort(Li)
print(List)