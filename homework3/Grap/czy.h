#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
namespace czy
{
	
struct node
{
	string s1, s2;
	int time;
	double price;
	int type;
}a[10005];
int cnt = 0;
int map[105][105] = {0};
int n=5;
int vis[105];
vector<int>tp,ans;
int minans=1e9;
void dfs(int x,int ans1)
{
	bool p=1;
	for(int i=1;i<n;i++)
	{
		if(vis[i])continue;
		if(map[x][i]!=-1)
		{
			p=0;
			vis[i]=1;tp.push_back(i);
			dfs(i,ans1+map[x][i]);
			vis[i]=0;tp.pop_back();
		}
	}
	if(p)
	{
		if(map[x][0]==-1)return;
		ans1+=map[x][0];
		if(ans1<minans)
		{
			minans=ans1;
			ans=tp;
		}
	}
}

void init1(vector<string>v, int type)
{
	memset(czy::map, -1, sizeof czy::map);
	czy::minans = 1e9;
	for (int i = 1; i <= cnt; i++)
	{
		//	cout<<a[i].type<<" "<<type<<endl;
		if (a[i].type != type)continue;
		for (int k = 0; k < v.size(); k++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (a[i].s1 == v[k] && a[i].s2 == v[j])
				{
					if (type == 2)czy::map[k][j] = a[i].time;
					else czy::map[k][j] = a[i].price;
					//	cout<<v[k]<<" "<<v[j]<<" "<<czy::map[k][j]<<endl; 
				}
			}
		}
	}
}
double string_to_double(string s)
{
	double x = 0;
	int j = s.size();
	for (int i = 0; i < s.size(); i++)
	{
		int tp = s[i] - '0';
		if (tp > 10 || tp < 0)
		{
			j = i + 1;
			break;
		}
		x *= 10;
		x += tp;
	}
	double y = 0;
	for (int i = j; i < s.size(); i++)
	{
		int tp = s[i] - '0';
		y *= 10;
		y += tp;
	}
	while (y > 1)y *= 0.1;
	return x + y;
}
void read(int type)
{
	string last;
	string s1, s2, s3, s4;
	getline(cin, s1);//cin.get();
	int time, price;
	while (1)
	{
		cin >> s1;
		if (s1 == "end")break;
		cin >> s2 >> s3 >> s4;
		int time = string_to_double(s4);
		double price = string_to_double(s3);
		a[++cnt] = { s1,s2,time,price,type };
		last = s3;


	}
}
void read_data()
{
	freopen("1.txt", "r", stdin);
	read(1);
	freopen("CON", "r", stdin);
	cin.clear();
	freopen("2.txt", "r", stdin);
	read(2);
	freopen("CON", "r", stdin);
	cin.clear();
}
void split(int n1,string s,vector<string>&v)
{
	int j=0;
	for(int i=1;i<=n1;i++)
	{
		string s1="";
		while(s[j]!=' ')
		{
			s1+=s[j];
			j++; 
		}
		v.push_back(s1);
		j++;
		
	}
	czy::n=n1+1;
	
}
vector<int> Design_path(vector<string>v,int type)
{
	read_data();
	init1(v,type);
	dfs(0,0);
	return ans;
}
string int_to_string(int x)
{
	string s="";
	while(x>0)
	{
		int tp=x%10;
		s=(char)(tp+'0')+s;
		x/=10;
	}
	return s;
}
}
/*
int main()
{
	czy::Design_path();
}*/
