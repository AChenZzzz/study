#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-09 12:32
#@Author: CWMDADADA
#@File  : LinkList.py

class Node:
    def __init__(self, item):
        self.item = item
        self.next = None

def creatLinkListHead(dataSet):
    head = Node(dataSet[0])

    for element in dataSet[1:]:
        node = Node(element)
        node.next = head
        head = node
    return head

def creatLinkListTail(dataSet):
    head = Node(dataSet[0])
    tail = head
    for elemnent in dataSet[1:]:
        node = Node(elemnent)
        tail.next = node
        tail = node
    return head


def insLinkList(data, dataSet):
    curNode = dataSet
    data.next = curNode.next
    curNode.next = data

def delLinkList(data, dataSet):
    curNode = dataSet
    data = curNode.next
    curNode.next = curNode.next.next
    del data

dataSet = creatLinkListTail([1, 2, 3])
while dataSet:
    print(dataSet.item, end=',')
    dataSet = dataSet.next