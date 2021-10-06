#!/usr/bin/env python
# -*- coding:utf-8 -*-
#@Time  : 2021-02-07 23:53
#@Author: CWMDADADA
#@File  : Maze.py
from collections import deque

maze = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 0, 0, 1],
    [1, 1, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
]

dirs =[
    lambda x,y:(x+1, y),
    lambda x,y:(x-1, y),
    lambda x,y:(x, y-1),
    lambda x,y:(x, y+1)
]

def mazePathStack(x1, y1, x2, y2):
    stack = []
    stack.append((x1, y1))
    while(len(stack) > 0):
        curNode = stack[-1]             #栈顶
        #搜索四个方向
        if curNode[0] == x2 and curNode[1] == y2:
            # 走到终点
            for p in stack:
                print(p)
            return True
        for dir in dirs:
            nextNode = dir(curNode[0], curNode[1])
            #如果下个节点能走
            if maze[nextNode[0]][nextNode[1]] == 0:
                stack.append(nextNode)
                maze[nextNode[0]][nextNode[1]] = 2
                #表示走过了
                break
        else:
            maze[nextNode[0]][nextNode[1]] = 2
            stack.pop()
    else:
        print("没有路")
        return False

def printQueue(path):
    curNode = path[-1]
    realPath = []
    print(curNode[2])
    while curNode[2] != -1:
        realPath.append(curNode[0:2])
        curNode = path[curNode[2]]
    realPath.append(curNode[0:2])
    realPath.reverse()
    for node in realPath:
        print(node)

def mazePathQueue(x1, y1, x2, y2):
    queue = deque()
    queue.append((x1, y1, -1))
    path = []
    while len(queue) > 0:
        curNode = queue.pop()
        path.append(curNode)
        if curNode[0] == x2 and curNode[1] == y2:
            print("into print")
            printQueue(path)
            return True
        for dir in dirs:
            nextNode = dir(curNode[0], curNode[1])
            if maze[nextNode[0]][nextNode[1]] == 0:
                queue.append((nextNode[0], nextNode[1], len(path) - 1))
                maze[nextNode[0]][nextNode[1]] = 2
    else:
        print("没有路")
        return False


print("Queue")
mazePathQueue(1,1,8,8)