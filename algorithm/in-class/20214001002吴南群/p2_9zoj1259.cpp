#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,i,count;
	int target[1000];//目标序列 
	stack<int> sk;
	while(cin>>n&&n!=0)
	{
		while(cin>>target[0]&&target[0])
		{
			for(i=1;i<n;i++)
				cin>>target[i];
			count=1;//顺序序列 
			i=0;//目标序列下标 
			while(i<n)
			{
				if(count==target[i])//当前号码与目标号码吻合，next 
				{
					count++;
					i++;
				}
    				else
				{
					if(!sk.empty()&&sk.top()==target[i])//当前不吻合，看上一个是否吻合 
					{
						sk.pop();
						i++;
					}
					else
					{
						if(count<=n)//看序列是否还在范围内 
							sk.push(count++);
						else
							break;
					}
				}
			}
			if(i==n)//正常退出while即序列可得到 
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
			while(!sk.empty())//清空栈，这个是考虑到当序列不可得到时，栈内有残留 
				sk.pop();
		}
		cout<<endl;
	}
	return 0;
}