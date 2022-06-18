#include <iostream>
#include <queue>
#include <cstdio>
#define max 60010
using namespace std;
struct message
{
	char name[1000];
	int cs;
	int yxj;
	int time;
	bool operator < (const message &a)const
	{
		return a.yxj<yxj;
	}
}z;
int main()
{
	priority_queue<struct message>q;
	char sent[4];
	int count=0;
	while(scanf("%s",sent)!=EOF)
	{
		if(sent[0]=='G')
		{
			if(q.size()==0)
			{
				printf("EMPTY QUEUE!\n");
			}
    			else 
			{
				printf("%s %d\n",q.top().name,q.top().cs);
				q.pop();
			}
		}
		else if(sent[0]=='P')
		{
			scanf("%s %d %d",z.name,&z.cs,&z.yxj);
			q.push(z);
		}
	}
}