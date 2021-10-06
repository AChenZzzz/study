#include"stdlib.h"
#include"stdio.h"

#define MAXSIZE 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int SElemType;
typedef int Status;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

Status StackInit(SqStack *S);
Status StackEmpty(SqStack S);
Status StackLength(SqStack S);
Status StackClear(SqStack *S);
Status StackDetory(SqStack *S);
Status StackPush(SqStack *S, int e);
Status StackPop(SqStack *S,SElemType *e);

void StackInit_Link(LinkStack *S);
Status StackEmpty_Link(LinkStack S);
Status StackPush_Link(LinkStack *S,SElemType e);
Status StackPop_Link(LinkStack *S,SElemType *e);
SElemType StakcGetTop_Link(LinkStack S);

int main(){
    LinkStack S;
    SElemType e;

    StackInit_Link(&S);
    StackPush_Link(&S,2);
    StackPush_Link(&S,3);

    StackPop_Link(&S, &e);
    e = StakcGetTop_Link(S);
    printf("%d\n",e);
    return 0;

}
//��ʼ��
Status StackInit(SqStack *S){
    S->base = (SElemType*)malloc(sizeof(SElemType)*MAXSIZE);

    if (!S->base)
        return OVERSIZE;
    S->top = S->base;
    return 0;
}
//�ж��Ƿ�Ϊ��
Status StackEmpty(SqStack S){
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
//����
Status StackLength(SqStack S){
    return S.top - S.base;
}
//���
Status StackClear(SqStack *S){
    if(S->base)
        S->top = S->base;
    return OK;
}
//����
Status StackDetory(SqStack *S){
    if(S->base){
        free(S->base);          //����ع��ڴ�
        S->stacksize = 0;       //�ṹ����ֵ����
        S->base = NULL;
        S->top = NULL;
    }
    return OK;
}
//��ջ
Status StackPush(SqStack *S, int e){
    if((S->top - S->base) == S->stacksize)
        return OVERSIZE;
    *(S->top) = e;
    S->top++;
    return OK;
}
//��ջ
Status StackPop(SqStack *S,SElemType *e){
    if(S->top == S->base)
        return UNDERSIZE;
    --(S->top);
    *e = *(S->top);
    return OK;
}

//��ջ��ʼ��
void StackInit_Link(LinkStack *S){
    S = NULL;
}
//��ջ�Ƿ�Ϊ��
Status StackEmpty_Link(LinkStack S){
    if(S == NULL)
        return TRUE;
    else
        return FALSE;
}
//��ջ��ջ
Status StackPush_Link(LinkStack *S,SElemType e){

    LinkStack p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = (*S);            //���½ڵ����ջ��
    (*S) = p;                  //�޸�ջ��ָ��
    return OK;
    
}
//��ջ��ջ
Status StackPop_Link(LinkStack *S,SElemType *e){
    LinkStack p;
    if(S == NULL)
        return ERROR;
    
    *e = (*S)->data;
    p = (*S);
    (*S) = (*S)->next;
    free(p);
    return OK;
    
}
//ȡջ��ֵ
SElemType StakcGetTop_Link(LinkStack S){

    if(S != NULL)
        return S->data;
    else
        return 0;
}

