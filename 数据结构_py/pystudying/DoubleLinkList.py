#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-09 15:45
#@Author: CWMDADADA
#@File  : DoubleLinkList.py

class Node():
    def __init__(self, item):
        self.item = item
        self.next = None
        self.prior = None

def insLinkList(data, dataSet):
    curNode = dataSet
    data.next = curNode.next
    curNode.next.prior = data
    data.prior = curNode
    curNode.next = data

def delLinkList(data, dataSet):
    curNode = dataSet
    data = curNode.next
    curNode.next = data.next
    data.next.prior = curNode
    del data