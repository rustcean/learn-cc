// TSP问题
//回溯--暴力枚举剪枝,深度优先- 只能算到 13
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 100
using namespace std;
double xd[MAX],yd[MAX];       //记录为止点
int n;                        //城市个数
double a[MAX][MAX];           //城市间距离
int x[MAX];                   //记录路径
double bestx[MAX] ={0.0};     //记录最优路径
double bestp = 65533;         //最短路径长
double cp=0;                  //当前路径长

void backpack(int t){
    if(t>n){//如果
        if((a[x[n]][1]) && (a[x[n]][1]+cp <bestp)){
            bestp =a[x[n]][1]+cp;//如果长度比以前的小
            for(int i=1; i<=n;i++){
                bestx[i]=x[i];
            }
        }
    }else{
        for(int i= t;i<=n;i++){
            /*约束为当前节点到下一节点的长度不为0,限界为走过的长度+
             当前要走的长度之和小于最优长度--*/
            if((a[x[t-1]][x[i]]) && (cp+a[x[t-1]][x[i]]<bestp/*做为剪枝的作用*/)){
                swap(x[t],x[i]);
                cp+=a[x[t-1]][x[t]];
                backpack(t+1);  
                cp-=a[x[t-1]][x[t]];//回溯
                swap(x[t],x[i]);
            }
        }
    }
}
//计算距离
double getdist(double x1,double y1,double x2,double y2){
    if(x1==x2 && y1==y2)
        return 0.0;
    else{
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
}
//将距离进行编入表格
void dist(double x[],double y[],int n){
    for(int i=1;i<=n;i++){
        a[i][i]=0.0;
        for(int j=i+1;j<=n;j++)
            a[j][i]=a[i][j]=getdist(x[i],y[i],x[j],y[j]);
    }
}

int main(){
    cout<<"输入城市个数和城市的坐标:"<<endl;
    cin>>n;         //顶点数
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        cin>>xd[i]>>yd[i];
    }    

    dist(xd,yd,n);
    backpack(2);//从2开始

    cout<<"最优路径:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<bestx[i]<<" ";
    }
    cout<<bestx[1]<<endl;
    cout<<"最短路径值为: "<<bestp<<endl; 
    return 0;
}