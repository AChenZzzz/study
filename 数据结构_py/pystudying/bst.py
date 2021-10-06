#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-09 17:54
#@Author: CWMDADADA
#@File  : bst.py


class BiTreeNode:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
        self.parent = None

class BST:
    def __init__(self, li=None):
        self.root = None
        if li:
            for val in li:
               self.insertNorec(val)
    def insert(self, node, value):
        if not node:
            node = BiTreeNode(value)
        elif value < node.data:
            node.lchild = self.insert(node.lchild, value)
            node.lchild.parent = node
        elif value > node.data:
            node.rchild = self.insert(node.rchild, value)
            node.rchild.parent = node
        return node

    def insertNorec(self, val):
        p = self.root
        if not p:
            self.root = BiTreeNode(val)
            return
        while True:
            if val < p.data:
                if p.lchild:
                    p = p.lchild
                else:
                    p.lchild = BiTreeNode(val)
                    p.lchild.parent = p
                    return
            elif val > p.data:
                if p.rchild:
                    p = p.rchild
                else:
                    p.rchild = BiTreeNode(val)
                    p.rchild.parent = p
                    return
            else:
                return
    def preOrder(self,root):
        if root:
            print(root.data, end=',')
            self.preOrder(root.lchild)
            self.preOrder(root.rchild)

    def inOrder(self,root):
        if root:
            self.inOrder(root.lchild)
            print(root.data, end=',')
            self.inOrder(root.rchild)

    def postOrder(self,root):
        if root:
            self.postOrder(root.lchild)
            self.postOrder(root.rchild)
            print(root.data, end=',')

    def remove_Node_1(self, node):
        if not node.parent:
            self.root = None
        if node == node.parent.lchild:
            node.parent.lchild = None
        else:
            node.parent.rchild = None
    def remove_Node_2(self, node):
        if not node.parent:
            self.root = node.lchild
            node.lchild.parent = None
        elif node == node.parent.lchild:
            node.parent.lchild = node.lchild
            node.lchild.parent = node.parent
        else:
            node.parent.rchild = node.rchild
            node.rchild.parent = node.parent
    def remove_Node_3(self, node):
        if not node.parent:
            self.root == node.rchild
        elif node == node.parent.lchild:
            node.parent.lchild = node.rchild
            node.rchild.parent = node.parent
        else:
            node.parent.rchild = node.rchild
            node.rchild.parent = node.parent
    def delete(self, val):
        if self.root:
            node = self.query_no_rec(val)
            if not node:
                return False
            if not node.lchild and not node.rchild:
                self.remove_Node_1(node)
            elif not node.rchild:
                self.remove_Node_2(node)
            elif not node.lchild:
                self.remove_Node_3(node)
            else:
                min_mode = node.rchild
                while min_mode.lchild:
                    min_mode = min_mode.lchid
                node.data = min_mode.data
                if min_mode.rchild:
                    self.remove_Node_2(min_mode)
                else:
                    self.remove_Node_3(min_mode)

tree = BST([4,6,7,9,2,1,3,5,8])
print("...")
tree.preOrder(tree.root)