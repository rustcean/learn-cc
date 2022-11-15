#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSons 3
typedef char ElemType;
typedef struct node
{
    ElemType data[15];     //结点的值
    struct node *sons[MaxSons];    //指向孩子结点
}TSonNode;      //孩子链存储结构中的结点类型
typedef struct
{
    char N[15];
    char n[15];
}array;
//读取文件内容到数组R中
void ReadFile(array R[],FILE *fp,int &n)
{
     while((fscanf(fp,"%s",R[n].N))!=EOF&&(fscanf(fp,"%s",R[n].n))!=EOF)
        n++;
}

//创建一颗树
TSonNode *CreateTree(char str[],array R[],int n)
{
    TSonNode *t;
    int k,i=0,j=0;
    t=(TSonNode *)malloc(sizeof(TSonNode));
    strcpy(t->data,str);
    for(k=0;k<MaxSons;k++)
      t->sons[k]=NULL;
    while(i<n)
    {
       if(strcmp(R[i].N,str)==0)
       {
           t->sons[j]=CreateTree(R[i].n,R,n);
           j++;
       }
       i++;
    }
    return t;
}
