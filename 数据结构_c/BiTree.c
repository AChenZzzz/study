#include"stdlib.h"
#include"stdio.h"

#define MAXSIZE 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;

typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode, *BiTree;

typedef struct TriBiNode{
    TElemType data;
    struct BiNode *lchild,*rchild,*parent;
}TriBiNode, *TriBiTree;

typedef struct{
    int data[MAXSIZE];
    int front, rear;
}SqQueue;
//先序遍历
Status PreOrderTraverse(BiTree T){
    if(T == NULL)
        return OK;
    else{
        printf("%c\t",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }

    return OK;
}
//中序遍历
Status MidOrderTraverse(BiTree T){
    if(T == NULL)
        return OK;
    else{
        PreOrderTraverse(T->lchild);
        printf("%d\t",T->data);
        PreOrderTraverse(T->rchild);
    }

    return OK;
}
//后序遍历
Status LastOrderTraverse(BiTree T){
    if(T == NULL)
        return OK;
    else{
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        printf("%d\t",T->data);
    }

    return OK;
}
//非递归中序
/*
Status InOrderTraverse(BiTree T){
    BiTree p;
    int q;

    InitStack(S);
    p = T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(S,p->data);
            p = p->lchild;
        }
        else{
            Pop(S, q);
            printf("%d\t",q);
            p = p->rchild;
        }
    }
    return OK;
}
*/
//创造
void CreatBiTree(BiTree *T){
    char ch = '0';
    scanf("%c\n",&ch);
    if( ch == '#')
        *T = NULL;
    else{
        *T = (BiNode *)malloc(sizeof(BiNode));
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;

        CreatBiTree(&((*T)->lchild));
        CreatBiTree(&((*T)->rchild));

    }
    return ;
}
//深度
int Depth(BiTree T){
    int m,n;

    if(T == NULL)
        return 0;
    else{
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m>n)
            return (m+1);
        else
            return (n+1);
    }
}
//结点数
Status NodeCount(BiTree T){
    if(T == NULL)
        return 0;
    else
        return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
}
//叶子结点数
Status NodeCount_child(BiTree T){
    if(T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return (NodeCount_child(T->lchild) + NodeCount_child(T->rchild));
    
}

int main(){
    BiNode* T;
    CreatBiTree(&T);

    printf("Depth:%d\n",Depth(T));
    printf("Count:%d\n",NodeCount(T));
    printf("Left:%d\n",NodeCount_child(T));
    PreOrderTraverse(T);
    

    return 0;
}