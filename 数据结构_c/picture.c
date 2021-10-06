#include"stdlib.h"
#include"stdio.h"
#include"string.h"

#define MVNum 100
#define MAX_BIT 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MaxInt 65532

typedef char VerTexType;
typedef int Status;
typedef int ArcType;
typedef int OtherInfo;

typedef struct{ 
    VerTexType vexs[MVNum];         //顶点表
    ArcType arcs[MVNum][MVNum];     //邻接矩阵
    int vexnum,arcnum;              //图的当前点数和边数
}AMGraph;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;                 //和边相关的信息
}ArcNode;

typedef struct VNode{
    VerTexType data;                //顶点信息
    ArcNode *firstarc;              //指向第一条依附该顶点的边
}VNode,AdjList[MVNum];

typedef struct{
    AdjList vertices;               //bertices--vertex的复数
    int vexnum,arcnum;              //图的当前顶点数和弧数
}ALGraph;

int LocateVex(AMGraph G, VerTexType u){
    int i;
    for(i = 0; i< G.vexnum; i++)
        if( u == G.vexs[i])
            return i;
    return -1;
}

int LocateVex_Link(ALGraph G, VerTexType u){
    int i;
    for(i = 0; i< G.vexnum; i++)
        if( u == G.vertices[i].data)
            return i;
    return -1;
}

Status CreatUDN(AMGraph *G){
    int x,y;

    (*G).vexnum = 4;
    (*G).arcnum = 4;

    for(int i = 0;i<(*G).vexnum;i++)
        (*G).vexs[i] = i + 1;

    for (int i = 0; i < (*G).vexnum; i++)
        for (int j = 0; j < (*G).arcnum; j++)
        {
            (*G).arcs[i][j] = MaxInt;
        }
    
    for (int k = 0; k < (*G).arcnum; k++)
    {
        x = LocateVex(*G, (k + 1));
        y = LocateVex(*G, (k + 2));
//        (*G).arcs[x][y] = w;
        (*G).arcs[x][y] = 1;
        (*G).arcs[x][y] = (*G).arcs[y][x];
    }
    return OK;
}

Status CreatUDN_Link(ALGraph *G){
    int v1,v2;
    int x,y;

    ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));
    ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));


    (*G).vexnum = 4;
    (*G).arcnum = 4;

    for (int i = 0; i < (*G).vexnum; i++)
    {
        scanf("%d\n",&(*G).vertices[i].data);
        (*G).vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < (*G).arcnum; k++)
    {
        scanf("%d,%d\n",v1,v2);
        x = LocateVex_Link(*G, v1);
        y = LocateVex_Link(*G, v2);
    p1->adjvex = y;
    p1->nextarc = (*G).vertices[x].firstarc;
    (*G).vertices[x].firstarc = p1;             //头插法

    p2->adjvex = x;
    p2->nextarc = (*G).vertices[y].firstarc;
    (*G).vertices[y].firstarc = p2;
    }
    return OK;

}

void DFS(AMGraph G,int v,int n){
    int *visited;
    visited = (int*)malloc(sizeof(int)*n);
    printf("%d\n",v);
    visited[v] = 1;
    for (int w = 0; w < G.vexnum; w++)
    {
        if((G.arcs[v][w]!=0)&&(!visited[w]))
            DFS(G, w);
    }
    
    
}