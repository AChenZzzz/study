#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-03 18:39
#@Author: CWMDADADA
#@File  : Stack.py
class stack:
    def __init__(self):
        self.stack = []
    def push(self, element):
        self.stack.append(element)
    def pop(self):
        return self.stack.pop()
    def getpop(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            return None

Stack = stack()
Stack.push(1)
Stack.push(2)
Stack.push(3)
print(Stack.pop())