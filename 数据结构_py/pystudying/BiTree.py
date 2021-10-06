#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-09 16:50
#@Author: CWMDADADA
#@File  : BiTree.py

from collections import deque

class BiTreeNode:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None

a = BiTreeNode("A")
b = BiTreeNode("B")
c = BiTreeNode("C")
d = BiTreeNode("D")
e = BiTreeNode("E")
f = BiTreeNode("F")
g = BiTreeNode("G")
e.lchild = a
e.rchild = g
a.rchild = c
c.lchild = b
g.rchild = f
root = e

def preOrder(root):
    if root:
        print(root.data, end=',')
        preOrder(root.lchild)
        preOrder(root.rchild)

def inOrder(root):
    if root:
        inOrder(root.lchild)
        print(root.data, end=',')
        inOrder(root.rchild)

def postOrder(root):
    if root:
        postOrder(root.lchild)
        postOrder(root.rchild)
        print(root.data, end=',')

def levelOrder(root):
    queue = deque()
    queue.append(root)
    while len(queue) > 0:
        node = queue.popleft()
        print(node.data, end=',')
        if node.lchild:
            queue.append(node.lchild)
        if node.rchild:
            queue.append(node.rchild)

levelOrder(root)
