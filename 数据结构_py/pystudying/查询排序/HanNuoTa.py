#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-01 12:10
#@Author: CWMDADADA
#@File  : HanNuoTa.py

def hanNuoTa( n, a, b, c):
    if n > 0:
        hanNuoTa(n-1, a, c, b)
        print("moving From %s to %s"%( a, c))
        hanNuoTa(n-1, b , a, c)

hanNuoTa(10, 'A' ,'B' ,'C')