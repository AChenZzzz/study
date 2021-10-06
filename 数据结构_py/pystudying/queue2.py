#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 22:30
#@Author: CWMDADADA
#@File  : queue2.py

from collections import deque
"""
q = deque([1,2,3], 5)
#单向
q.append(4)
#队尾进队
q.popleft()
#队首出队

#双向队列
q.appendleft(1) 
#队首进队
q.pop()
#队尾出队
"""
def tail(n):
    with open('test.txt','r') as file:
        q = deque(file , n)            #进队test然后队尾出
        return q
for line in tail(5):
    print(line , end='')