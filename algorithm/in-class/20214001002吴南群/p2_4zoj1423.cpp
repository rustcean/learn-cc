#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
	stack<char> sk;
	char s[256],result[256];
	int i,j,t;
	cin>>t;
	getchar();
	while(t--)
	{
		cin.getline(s,256);
		for(i=0,j=0;s[i]!='\0';i++)//初始化
		{
			if(s[i]>='A'&&s[i]<='Z'||s[i]=='+'||s[i]=='-')
				result[j++]=s[i];
			else
			{
				switch(s[i])
				{
				case '(':
					if(j==0||result[j-1]!='-')
						sk.push('(');
					else
					{
    						result[j++]='(';
						sk.push('?');
					}
					break;
				case ')':
					if(sk.top()!='(')
						result[j++]=')';
					sk.pop();
					break;
				}
			}
		}
		result[j]='\0';
		for(i=0;i<j;i++)
		{
			if(result[i]!='*')
			{
				if(result[i]=='('&&result[i+2]==')')
				{
					result[i+2]='*';
					continue;
    				}
				cout<<result[i];
			}
		}
		cout<<endl;
		while(!sk.empty()) 
			sk.pop();
	}
	return 0;
}