// TSP问题
//回溯--暴力枚举剪枝,深度优先?
#include <iostream>
#include <algorithm>

#define MAX 100

using namespace std;

int n;                  //城市个数
int a[MAX][MAX];        //城市间距离
int x[MAX];             //记录路径
int bestx[MAX] ={0};    //记录最优路径
int bestp = 65533;      //最短路径长
int cp=0;               //当前路径长

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
            if((a[x[t-1]][x[i]]) && (cp+a[x[t-1]][x[i]]<bestp)){
                swap(x[t],x[i]);
                cp+=a[x[t-1]][x[t]];//增添
                backpack(t+1);  
                cp-=a[x[t-1]][x[t]];//回退
                swap(x[t],x[i]);
            }
        }
    }
}

int main(){
    cout<<"输入城市个数和城市之间的距离(0表示城市间不通或者本城市): "<<endl;
    cin>>n;         //顶点数
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    backpack(2);//从2开始

    cout<<"最优路径:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<bestx[i]<<" ";
    }
    cout<<bestx[1]<<endl;
    cout<<"最短路径值为: "<<bestp<<endl; 
    return 0;
}
