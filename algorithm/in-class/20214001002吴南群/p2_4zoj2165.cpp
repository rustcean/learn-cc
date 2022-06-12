//

#include<stdio.h>
#include<string.h>
char map[30][30];
int num,n,m,book[30][30];
int xx[4][2]={0,-1,
			  -1,0,
			  0,1,
			  1,0};
void dfs(int x,int y)
{
	int k,i,j,tx,ty;
	for(k=0;k<4;k++)
	{
		tx=x+xx[k][0];
		ty=y+xx[k][1];
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			num++;
			dfs(tx,ty);
		}
	}
	return;
}
int main()
{
	int i,j,x,y;
	while(scanf("%d%d",&m,&n))
	{
		if(n==0&&m==0)
			break;
		num=0;
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(map[i][j]=='#')
					book[i][j]=1;
				else
					book[i][j]=0;
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
		num++;
		book[x][y]=1;
		dfs(x,y);
		printf("%d\n",num);
	}
	return 0;
 } 