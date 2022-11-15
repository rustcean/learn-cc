#include<stdio.h>
#include<stdlib.h>
#include"Tree.cpp"
#define MaxSize 66
int main()
{
    int n=0;
    TSonNode *t;
    array R[MaxSize];
    FILE *fp;
    if((fp=fopen("table.txt","r"))==NULL)      //以只读方式打开table.txt文件
    {
        printf("error!cannot open the file!");
        exit(1);
    }
    printf("读取文件内容存入数组R中\n");
    ReadFile(R,fp,n);
    printf("输出数组R:\n");
    for(int i=0;i<n;i++)
        printf("%s %s\n",R[i].N,R[i].n);  //输出R数组查看是否读取正确
    printf("\n由数组R创建树T,");
    t=CreateTree(R[0].N,R,n);   //创建一颗树
}