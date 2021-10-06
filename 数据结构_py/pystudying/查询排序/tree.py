#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-09 16:31
#@Author: CWMDADADA
#@File  : tree.py

class Node:
    def __init__(self, name, type='dir'):
        self.name = name
        self.type = type
        self.children = []
        self.parent = None
    def __repr__(self):
        return self.name

class fileSystemTree:
    def __init__(self):
        self.root = Node("/")
        self.now = self.root
    def mkdir(self, name):
        if name[-1] != "/":
            name += "/"

        node = Node(name)
        self.now.children.append(node)
        node.parent = self.now

    def ls(self):
        return self.now.children

    def cd(self, name):
        if name[-1] != "/":
            name += "/"
        if name == "../":
            self.now = self.now.parent
            return True

        for child in self.now.children:
            if child.name == name:
                self.now = child
                return True
        raise ValueError("invaild dir")

tree = fileSystemTree()
tree.mkdir("var/")
tree.mkdir("bin/")
tree.mkdir("usr/")
tree.cd("bin/")
tree.mkdir("python/")

print(tree.ls())