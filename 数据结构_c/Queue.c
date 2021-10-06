#include"stdlib.h"
#include"stdio.h"

#define MAXSIZE 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int QElemType;
typedef int Status;

typedef struct{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

typedef struct Qnode{
    QElemType data;
    struct Qnode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(SqQueue *Q){

    Q->base = (QElemType*)malloc(sizeof(QElemType)*MAXSIZE);
    if(!Q->base)
        return OVERSIZE;
    Q->front = Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue Q){
    return (Q.rear-Q.front  + MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e){
    if((Q->rear + 1)%MAXSIZE == Q->front)
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e){
    if(Q->rear == Q->front)
        return ERROR;

    *e = Q->base[Q->front];
    Q->front = (Q->front + 1)%MAXSIZE;
    return OK;
}

QElemType GetHead(SqQueue Q){
    if(Q.front != Q.rear)
        return Q.base[Q.front];
}

Status InitQueue_Link(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue_Link(LinkQueue *Q){
    QNode *p;
    while (Q->front)
    {
        p = Q->front->next;
        free(Q->front);
        Q->front = p;
    }
    return OK;
}

Status EnQueue_Link(LinkQueue *Q, QElemType e){
    QNode *p;
    p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;

    Q->rear->next = p;
    Q->rear = p;

    return OK;
}

Status DeQueue_Link(LinkQueue *Q, QElemType *e){
    QNode *p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(Q->rear == Q->front)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;

    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;


}

int main(){
    SqQueue S;
    QElemType e;
    InitQueue(&S);

    EnQueue(&S, 1);
    EnQueue(&S, 2);
    EnQueue(&S, 3);
    EnQueue(&S, 4);
    EnQueue(&S, 5);
    DeQueue(&S,&e);
    DeQueue(&S,&e);
    printf("%d\n",QueueLength(S));
    printf("%d\n",e);

return 0;
}