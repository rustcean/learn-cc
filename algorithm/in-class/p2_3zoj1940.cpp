/*  zoj 1940--AC
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int l,r,c;
char mp[40][40][40];
int sx,sy,sz,ex,ey,ez;
int disx[6]={1,-1,0,0,0,0};
int disy[6]={0,0,0,0,-1,1};
int disz[6]={0,0,1,-1,0,0};
const int inf=9999999;
int ans;
struct node {
    int x,y,z;
    int step;
};
int check(int x,int y,int z) {
    if(x<0||y<0||z<0||x>=l||y>=r||z>=c) return 1;
    if(mp[x][y][z]=='#') return 1;
    return 0;
}
void bfs() {
    queue<node> q;
    node a,next;
    a.x=sx;
    a.y=sy;
    a.z=sz;
    a.step=0;
    q.push(a);
    mp[sx][sy][sz]='#';
    while(!q.empty()) {
        a=q.front();q.pop();
        if(a.x==ex&&a.y==ey&&a.z==ez)
            if(a.step<=ans) ans=a.step;
        for(int i=0;i<6;i++) {
            next.x=a.x+disx[i];
            next.y=a.y+disy[i];
            next.z=a.z+disz[i];
            next.step=a.step+1;
            if(check(next.x,next.y,next.z)) continue;
            mp[next.x][next.y][next.z]='#';
            q.push(next);
        }
    }

}
int main() {
//  freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&l,&r,&c)!=EOF) {
        if(l==0&&r==0&&c==0) break;
        for(int i=0;i<l;i++) {
            for(int j=0;j<r;j++) {
                scanf("%s",mp[i][j]);
            }
        }
        for(int i=0;i<l;i++) {
            for(int j=0;j<r;j++) {
                for(int x=0;x<c;x++) {
                    if(mp[i][j][x]=='S') {
                        sx=i;
                        sy=j;
                        sz=x;
                    }
                    if(mp[i][j][x]=='E') {
                        ex=i;
                        ey=j;
                        ez=x;
                    }
                }
            }
        }
        ans=inf;
        bfs();
        if(ans==inf) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}