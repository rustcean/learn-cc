// 匈牙利算法
// 复杂度 O(n**3) n是节点数
#include <iostream> 
#include <cstring>
using namespace std;


const int MAXN=100; //最大节点数

int match[MAXN];    //记录匹配情况
bool vis[MAXN];     //记录是否访问过
bool g[MAXN][MAXN]; //邻接矩阵表示的二分图

int n,m;    //节点数和边数

bool dfs(int u){
    // 从节点u开始进行增广路查找
    for(int v=0;v<m;v++){
        if(g[u][v] && !vis[v]){
            // 如果u和v之间有边,且v没有被访问过
            vis[v]=true;    //标记已经被访问

            if(match[v]==-1 || dfs(match[v])){
                // 如果v没有被匹配,或v已经匹配但可以找到更好的匹配
                match[v]==u;    //更新v的匹配
                return true;    //返回查找成功
            }
        }
    }
    return false;   //如果不存在增广路,则返回查找失败
}

int maxMatch(){
    // 计算最大匹配数
    int cnt=0;  //记录匹配数

    memset(match,-1,sizeof(match)); //初始化为-1,都没有被匹配
    for(int u=0;u<n;u++){
        // 枚举所有左部节点
        memset(vis,false,sizeof(vis));  //每次查找时清空访问标记
        if(dfs(u))
            cnt++;  //如果从u出发可以找到增广路,则更新匹配数        
    }    
    return cnt;
}


int main(){
    cout<<"输入节点和边数"<<endl;
    cin>>n>>m;
    memset(g,false,sizeof(g));  //初始化邻接矩阵
    
    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;  //输入一条边的两个端点
        g[u][v]=true;   //邻接矩阵中标记
    }
    cout<<"最大匹配数: "<<maxMatch()<<endl; //输出
    return 0;
}


/*
6 5
1 4
1 5
2 5
2 6
3 4 
*/