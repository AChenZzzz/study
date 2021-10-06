#include"stdlib.h"
#include"stdio.h"

#define MAXSIZE 100
#define MAX_TREE_SIZE 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;
//顺序存储
typedef struct PTNode{
    TElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAXSIZE];
    int r,n;                //根结点的位置和结点个数
}PTree;
//链式存储
typedef struct CTNode{
    int child;
    struct CTNode *next;
}*ChildPtr;
typedef struct{
    TElemType data;
    ChildPtr firestchild;
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;                //根结点的位置和结点个数

}CTree;
//孩子兄弟表示法
typedef struct CSNode{
    TElemType data;
    struct CSNode *firestchild,*nextsibling;
}CSNode,*CSTree;