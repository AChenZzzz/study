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

#define MAXSIZE 100
//函数类型
typedef int Status;
typedef char ElemType;

typedef struct
{
    ElemType *elem;
    int Length;
}SqList;

Status InitList_Squeue(SqList* L);
void DestoryList_Squeue(SqList* L);
void ClearList_Squeue(SqList* L);
Status GetLengthList_Squeue(SqList* L);
Status EmptyList_Squeue(SqList* L);
Status GetElemList_Squeue(SqList* L, int i, ElemType e);
Status LocateElemList_Squeue(SqList* L, ElemType e);
Status InsertList_Squeue(SqList* L, ElemType e, int i);
Status DeleteList_Squeue(SqList* L, int i);
void OutputList(SqList* L);


int main(){
    int local_length = 0;

    SqList* L;

    InitList_Squeue(L);

    (*L).elem[0] = '1';
    (*L).elem[1] = '2';
    (L)->elem[2] = '3';
    (L)->elem[3] = '4';
    (L)->Length = 4;
    InsertList_Squeue(L, '6', 5);
    InsertList_Squeue(L, '7', 2);
    DeleteList_Squeue(L, 2);

    local_length = LocateElemList_Squeue(L, '2');
    printf("%d\n",local_length);
    OutputList(L);
    return 0;

}

//函数
//初始化线性表
Status InitList_Squeue(SqList* L){

    L->elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);

    if (!L->elem)
    {
        return OVERFLOW;
    }

    L->Length = 0;
    return 0;
}
//销毁线性表
void DestoryList_Squeue(SqList* L){

    if(L->elem)
        free(L->elem);
}
//清空线性表
void ClearList_Squeue(SqList* L){

    L->Length = 0;
}
//求线性表长度
Status GetLengthList_Squeue(SqList* L){
    return (L->Length);
}
//判断L是否为空
Status EmptyList_Squeue(SqList* L){

    if(L->Length == 0)
        return 1;
    else
        return 0;
}
//线性表取值
Status GetElemList_Squeue(SqList* L, int i, ElemType e){
    
    if(i<1 || i>L->Length)
        return ERROR;

    e = L->elem[i-1];
    return OK;
}
//查找
Status LocateElemList_Squeue(SqList* L, ElemType e){

    for(int i = 0; i < L->Length; i++){
        if(L->elem[i] == e)
            return i+1;
    }
    return 0;
}
//插入
Status InsertList_Squeue(SqList* L, ElemType e, int i){

    if(i<1 || i> L->Length + 1)
        return ERROR;
    if(L->Length == MAXSIZE)
        return ERROR;

    for (int j = L->Length - 1; j >= i-1; j--)
        (*L).elem[j+1] = L->elem[j];
    
    L->elem[i-1] = e;
    L->Length = L->Length + 1;
    return OK;
}
//删除
Status DeleteList_Squeue(SqList* L, int i){

    if(i<1 || i> L->Length)
        return ERROR;

    for (int j = i; j <= L->Length - 1; j++)
        L->elem[j-1] = L->elem[j];
    
    L->elem[L->Length] = 0;
    L->Length = L->Length - 1;

    return OK;
}
//打印
void OutputList(SqList* L){
    for (int i = 0; i <= L->Length - 1; i++)
    {
        printf("%c", L->elem[i]);
    }
    printf("\n");
}