#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-07 21:08
#@Author: CWMDADADA
#@File  : Hashing.py

class LinkList:
    class Node:
        def __init__(self, item=None):
            self.item = item
            self.next = None

    class LinkListIterator:
        def __init__(self, node):
            self.node = node
        def __next__(self):
            if self.node:
                curNode = self.node
                self.node = curNode.next
                return curNode.item
            else:
                raise StopIteration

        def __iter__(self):
            return self

    def __init__(self, iterable=None):
        self.head = None
        self.tail = None
        if iterable:
            self.extend(iterable)

    def append(self, obj):
        s = LinkList.Node(obj)
        if not self.head:
            self.head = s
            self.tail = s
        else:
            self.tail.next = s
            self.tail = s

    def extend(self, iterable):
        for obj in iterable:
            self.append(obj)

    def find(self, obj):
        for n in self:
            if n == obj:
                return True
        else:
            return False

    def __iter__(self):
        return self.LinkListIterator(self.head)
    def __repr__(self):
        return "<<"+",".join(map(str, self))+">>"

class hashTable:
    def __init__(self, size=101):
        self.size = size
        self.T = [LinkList() for i in range(self.size)]

    def h(self, k):
        return k % self.size

    def insert(self, k):
        i = self.h(k)
        if self.find(k):
            print("Duolicated")
        else:
            self.T[i].append(k)

    def find(self, k):
        i = self.h(k)
        return self.T[i].find(k)

hk = hashTable()
hk.insert(0)
hk.insert(1)

print(",".join(map(str, hk.T)))