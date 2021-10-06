#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 13:32
#@Author: CWMDADADA
#@File  : MergeSort.py
def merge(dataSet , low ,mid ,high):
    i = low
    j = mid + 1
    ltemp = []
    while i <= mid and j <= high:
        if dataSet[i] < dataSet[j]:
            ltemp.append(dataSet[i])
            i += 1
        else:
            ltemp.append(dataSet[j])
            j += 1
    while i <= mid:
        ltemp.append(dataSet[i])
        i += 1
    while j <= high:
        ltemp.append(dataSet[j])
        j += 1
    dataSet[low:high+1] = ltemp

def mergeSort(dataSet , low ,high):
    if low < high:
        mid = (low + high) //2
        mergeSort(dataSet , low, mid)
        mergeSort(dataSet , mid + 1, high)
        merge(dataSet , low, mid, high )

