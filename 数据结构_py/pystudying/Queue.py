#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 22:05
#@Author: CWMDADADA
#@File  : Queue.py
class Queue:
    def __init__(self , size = 100):
        self.queue = [0 for _ in range(size)]
        self.size = size
        self.rear = 0                           #队尾
        self.front = 0                          #队首

    def push(self , element):
        if not self.isFilled():
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = element
        else:
            raise IndexError("Queue is filled.")

    def pop(self):
        if not self.isEmpty():
            self.front = (self.front + 1) % self.size
            return self.queue[self.front]
        else:
            raise IndexError("Queue is empty.")
    #判断队空
    def isEmpty(self):
        return self.rear == self.front
    #判断队满
    def isFilled(self):
        return (self.rear + 1) % self.size == self.front

q = Queue(5)
for i in range(4):
    q.push(i)
print(q.pop())
q.push(4)