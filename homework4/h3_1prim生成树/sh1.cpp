// 抄的 从结果来看，应该是错的

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MaxSize=100;
const int MAX=9999;

//图类
class MGraph{
    string vertex[MaxSize];         // 图的顶点数量
    int adj[MaxSize][MaxSize];      //图的邻接矩阵
    int vertexNum,edgeNum;          //顶点数和边数

    public:
    MGraph(int n);
    int W(int i,int j);
    void InsertEdge(int i,int j,int p);
    int VexNum(){return vertexNum;}

    friend void Prim(MGraph &g,int u0);
};

// 函数
MGraph::MGraph(int n){
    vertexNum=n;                //顶点数
    edgeNum=0;                  //边数初始化为0
    memset(adj,0,sizeof(adj));  //将邻接矩阵所有元素初始化为0
}

void MGraph::InsertEdge(int i,int j,int p){
    // 插入顶点i,j依附的边以及该边的权值
    adj[i][j]=adj[j][i]=p;
    edgeNum++;
}

int MGraph::W(int i,int j){
    return adj[i][j];
}

void Prim(MGraph &g,int u0){
    int k;
    int n=g.VexNum();               //顶点数
    struct node{
       int adjvex;                  //
       int lowcost;                 //
    }closedge[MaxSize];
    closedge[u0].adjvex=u0;         //初始顶点
    closedge[u0].lowcost=0;         // ---

    for(int v=0;v<n;v++){           //初始化
        if(v!=u0){
            closedge[v].adjvex=u0;
            closedge[v].lowcost=g.W(u0,v);          //获取邻接矩阵的权值
        }
    }
    closedge[u0].lowcost=0;                         //开始点的权值默认为0
    
    for(int i=0;i<n-1;i++){                        //因为已经有一个点在图里了
        k=0;
        int minw=MAX;                               //用来找到最小值
        for(int v=0;v<n;v++){
            if(closedge[v].lowcost>0 && closedge[v].lowcost<minw){
                k=v;                                //位置
                minw=closedge[v].lowcost;           //最小值
            }
        }
        cout<<"("<<closedge[k].adjvex<<","<<k<<")"<<": "
        <<minw<<" "<<endl;
        closedge[k].lowcost=0;  //顶点k并入U集
        for(int v=0;v<n;v++){
            int w=g.W(k,v);
            if(closedge[v].lowcost!=0 && w < closedge[v].lowcost){
                closedge[v].lowcost=w;
                closedge[v].adjvex=k;
            }
        }
    }
}

int main(){
    struct Edge
    {
        int from,end,power;
    };
    
    int n=6;    //6个顶点
    int e=10;
    Edge b[]={
        {0,1,6},{0,2,1},{0,3,5},
        {1,2,5},{1,4,3},
        {2,3,5},{2,4,6},{2,5,4},
        {3,5,2},{4,5,6}
    };
    MGraph m(n);
    for(int k=0;k<e;k++){
        m.InsertEdge(b[k].from,b[k].end,b[k].power);
    }
    Prim(m,0);

    return 0;
}
