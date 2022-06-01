/**
ZOJ-1091
**/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int MAP[8][2]={{2,1},{2,-1},{-2,-1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
int a[8][2]={0};
struct  NodeStru
{
    int x;
    int y;
    int moves;
};

void bfs(NodeStru start)
{
    NodeStru end;
    end.x=5;
    end.y=7;
    queue <NodeStru> knight;//定义队列入列
    knight.push(start); //起始位置入列
    while(!knight.empty())
    {
        NodeStru temp=knight.front();
        knight.pop();
        if(temp.x=end.x&&temp.y==end.y)break;
        for(int i=0;i<8;i++)
        {
            int x=temp.x+MAP[i][0],y=temp.y+MAP[i][1];
            if(x>=0&&x<8&&y>=0&&y<8&&!a[x][y])
            {
                start.x=x,start.y=y;
                start.moves=temp.moves+1;
                knight.push(start);
                a[x][y]=1;
            }
        }
    }
}


int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int k=0;
        if(s1.compare(s2)==0)
        {
            cout<<"To get from "<<s1<<" to "<<s2<<"takes 0 knight moves"<<endl;
        }
        else 
        {
            memset(a,0,sizeof(a)); //这是cstring里的函数
            NodeStru startpos,endpos;
            startpos.x=s1[0]-'a';startpos.y=s1[1]-'1';
            a[startpos.x][startpos.y]=1;
            startpos.moves=0;
            endpos.x=s2[0]-'a',endpos.y=s2[1]-'1';
            bfs(startpos);
        }
    }
}









