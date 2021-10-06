#include"stdlib.h"
#include"stdio.h"
#include"string.h"

#define MAXSIZE 100
#define MAX_BIT 100
#define OVERSIZE -2
#define UNDERSIZE -1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef char TElemType;
typedef int Status;

typedef struct{
    int weight;
    int parent, lch,rch;
    char value;
}HTNode,*HuffmanTree;

typedef struct{
    char *data;
}*HuffmanCodeTree;


void Select(HuffmanTree HT, int number, int *s1, int *s2){
    int cpms = 0;
    int temp,temp1,temp2;
    for(int i = 1; i <= number; i++){
        if(HT[i].parent == 0){
            temp1 = HT[i].weight;
            *s1 = i;
            goto next_cmp;
        }
    }
next_cmp:
    for(int i = 1; i <= number; i++){
        if(HT[i].parent == 0 && HT[i].weight != temp1){
                temp2 = HT[i].weight;
                *s2 = i;
                goto last_cmp;
            }
    }

last_cmp:
    if(temp1 > temp2){
        temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }        
    for(int i = 1; i <= number; i++){
        if(HT[i].parent == 0 && (HT[i].weight <= temp1)){
            temp1 = HT[i].weight;
            *s1 = i;
        }    
    }
    for(int i = 1; i <= number; i++){
        if(HT[i].parent == 0 && HT[i].weight < temp2 && HT[i].weight >= temp1 && *s1 != i){
            temp2 = HT[i].weight;
            *s2 = i;
         }
                
    }
    
}

void CreatHuffmanTree(HuffmanTree *HT, int n){
    int m;
    int s1, s2;

    if(n<=1) 
        return ;
    m = 2*n - 1;                //数组总元素
    *HT = (HuffmanTree)malloc(sizeof(HTNode)*(m+1));     //0位置并未使用
    for(int i = 1; i <= m; i++){
        (*HT)[i].lch = 0;
        (*HT)[i].rch = 0;
        (*HT)[i].parent = 0;                               //85元素清零
        (*HT)[i].value = 'a' + i - 1;
    }
    /*
    for (int i = 1; i <= n; ++i){
        scanf("%d",&((*HT)[i].weight));                  //输入权重
    }
    */
   (*HT)[1].weight = 5;
   (*HT)[2].weight = 29;
   (*HT)[3].weight = 7;
   (*HT)[4].weight = 8;
   (*HT)[5].weight = 14;
   (*HT)[6].weight = 23;
   (*HT)[7].weight = 3;
   (*HT)[8].weight = 11;

    //合并产生二叉树
    for (int i = n+1; i <= m; i++){
    //寻找最小的两个结点
        Select(*HT, i-1, &s1, &s2);

        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;

        (*HT)[i].lch = s1;
        (*HT)[i].rch = s2;

        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}

void CreatHuffmanCode(HuffmanTree *HT, HuffmanCodeTree *HC, int n){
    char *cd;
    int start,c,f;
    *HC = (HuffmanCodeTree)malloc(sizeof(char*)*(n+1));
    cd = (char*)malloc(sizeof(char)*n);                 //缓存

    cd[n-1] = '\0';
    for(int i=1; i<= n; i++){
        start = n-1;
        c = i;
        f = (*HT)[i].parent;

        while (f != 0)
        {
            if((*HT)[f].lch == c)
                cd[--start] = '0';
            else    
                cd[--start] = '1';
            c = f;
            f = (*HT)[f].parent;
        }
        (*HC)[i].data = (char*)malloc(sizeof(char)*(n-start));
        strcpy((*HC)[i].data,&cd[start]);

        printf("第%d char:%c\t %s\n",i,(*HT)[i].value,(*HC)[i].data);
    }
    free(cd);

}

int main(){
int s1, s2;
HuffmanTree HT;
HuffmanCodeTree HC;
 
CreatHuffmanTree(&HT,8);
printf("\n");
CreatHuffmanCode(&HT, &HC,8);

   
    return 0;
}