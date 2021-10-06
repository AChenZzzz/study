#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-01 22:23
#@Author: CWMDADADA
#@File  : HeapSort.py

def sift(dataSet ,low, high):
    """
    :param dataSet: 列表
    :param low: 堆的根节点位置
    :param high: 堆的最后一个元素位置
    :return:
    """
    i = low                          #i最开始指向的根节点
    j = 2 * i + 1                    #j开始左叶子
    temp = dataSet[low]              #存堆顶
    while j <= high:                 #只要j位置有数
        if j + 1 <= high and dataSet[j + 1] < dataSet[j]:
            j = j + 1                #指向右叶子
        if dataSet[j] < temp:
            dataSet[i] = dataSet[j]
            i = j                    #往下看一层
            j = 2 * i + 1
        else:
            break
    dataSet[i] = temp                #temp放到某一个根节点

def heapSort(dataSet):
    length = len(dataSet)
    for i in range((length-2)//2 , -1, -1): #调整根部分的下标
        sift(dataSet ,i , length - 1)       #建堆完成
    for i in range(length - 1 , -1, -1):
        #i指向当前堆最后一个元素
        dataSet[0], dataSet[i] = dataSet[i], dataSet[0]
        sift(dataSet ,0, i - 1)
    print(dataSet)

def topk(dataSet , k):
    heap = dataSet[0:k]
    #前k个元素
    for i in range((k - 2)//2 , -1, -1):
        sift(heap , i, k - 1)
    #1.建堆
    for i in range(k , len(dataSet) - 1):
        if dataSet[i] > heap[0]:
            heap[0] = dataSet[i]
            sift(heap , 0, k-1)
    #2.遍历
    for i in  range(k-1 , -1, -1):
        heap[0], heap[i] = heap[i], heap[0]
        sift(heap , 0, i - 1)
    #3.出数
    return heap



dataSet = [i for i in range(10)]
import random
random.shuffle(dataSet)
print(dataSet)
mergeSort(dataSet , 0 , len(dataSet) - 1)
print(dataSet)