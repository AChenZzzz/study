#include"stdio.h"
#include"stdlib.h"
#include"string.h"

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//函数类型
typedef int Status;
typedef char ElemType;

typedef struct Lnode{
    ElemType data;
    struct Lnode* next;
}Lnode,*LinkList;

typedef struct Dnode{
    ElemType data;
    struct Dnode* prior,* next;
}Dnode,*DuLinkList;

Status ListInit_LinkList(LinkList* L);
Status ListEmpty_LinkList(LinkList L);
Status ListDestroy_LinkList(LinkList* L);
Status ListClear_LinkList(LinkList* L);
Status ListLength_LinkList(LinkList L);
Status GetElem_LinkList(LinkList L, int i, ElemType* e);
Lnode* LocateElem_LinkList(LinkList L, ElemType e);
Status ListInsert_LinkList(LinkList* L, int i, ElemType e);
Status ListDelete_LinkList(LinkList* L, int i, ElemType* e);

void CreatList_Head(LinkList* L, int n);
void CreatList_Rail(LinkList* L, int n);

int main(){

    LinkList L;
    printf("%d",InitList_LinkList(&L));

    return 0;
}
//初始化
Status ListInit_LinkList(LinkList* L){
    (*L) = (LinkList)malloc(sizeof(Lnode));
    (*L)->next = NULL;

    return  OK;
}
//判断是否为空
Status ListEmpty_LinkList(LinkList L){
    if (L->next)
        return 0;
    else
        return 1;
}
//链表销毁
Status ListDestroy_LinkList(LinkList* L){
    Lnode* p;
    while (*L)
    {
        p = *L;
        (*L) = (*L)->next;
        free(p);
    }
    return OK;
}
//链表清空
Status ListClear_LinkList(LinkList* L){
    Lnode* p,* q;
    p = (*L)->next;
    while (p)
    {      
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;

    return OK;
}
//链表表长
Status ListLength_LinkList(LinkList L){
    int length;
    Lnode* p;

    p = L->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}
//获取链表数据
Status GetElem_LinkList(LinkList L, int i, ElemType* e){
    int j = 1;
    Lnode* p;
    p = L->next;

    while (p && j<i)
    {
        p = p->next;
        ++j;
    }

    if(!p || j>i)
        return ERROR;

    e = p->next;
    return OK;
}
//获取链表中元素所在位置
Lnode* LocateElem_LinkList(LinkList L, ElemType e){

    Lnode* p;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
//插入
Status ListInsert_LinkList(LinkList* L, int i, ElemType e){
    Lnode* p;
    int j = 0;
    p = *L;
    while (p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j<i-1)
    {
        return ERROR;
    }

    Lnode* s;
    s = (Lnode*)malloc(sizeof(Lnode));

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}
//删除
Status ListDelete_LinkList(LinkList* L, int i, ElemType* e){
    Lnode* p, * q;
    int j = 0;

    while (p->next && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j<i-1)
    {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return OK;
}
//头插法
void CreatList_Head(LinkList* L, int n){
    Lnode* p;

    *L = (Lnode*)malloc(sizeof(Lnode));
    (*L)->next = NULL;

    for (int i = n; i > 0; --i)
    {
        p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%c",p->data);

        p->next = (*L)->next;
        (*L)->next = p;
    }  
}
//尾插法
void CreatList_Rail(LinkList* L, int n){
    Lnode* p,* r;

    *L = (Lnode*)malloc(sizeof(Lnode));
    (*L)->next = NULL;
    r = *L;
    for (int i = 0; i < n; i++)
    {
        p = (Lnode*)malloc(sizeof(Lnode));
        scanf("%c",p->data);

        p->next = NULL;
        r->next = p;
        r = p;
    } 
}
//循环合并
LinkList Connect(LinkList Ta, LinkList Tb){
    Lnode* p;

    p = Ta->next;
    Ta->next = Tb->next->next;
    free(Tb->next);
    Tb->next = p;
    return Tb;
}

void ListInsert_Dul(DuLinkList* L, int i, ElemType e){
    Dnode* s;

    s = (Dnode*)malloc(sizeof(Dnode));
    s->data = e;

    s->prior = (*L)->prior;
    (*L)->prior->next = s;

    s->next = *L;
    (*L)->prior = s;
    
}

void ListDelete_Dul(DuLinkList* L, int i, ElemType e){

    e = (*L)->data;
    (*L)->prior->next = (*L)->next;
    (*L)->next->prior = (*L)->prior;

    free(*L);

    return OK;
}