#include<bits/stdc++.h>
using namespace std;
#define sq(x) (x)*(x)
const int maxn=20;          
const int maxm=1000;

int n=16;                   //城市数量
int m=100;                  //免疫个体数量
int T=50;                   //免疫代数
int Ncl=50;                 //克隆数量 
double dist[maxn][maxn];    //记录城市间距离

struct cell
{
	int path[maxn];
	double fitness;
	bool operator <(const cell x)const
	{
		return fitness<x.fitness;
	}
}a[maxm],b[maxm];

vector<int>Path;    //用于随机生成路径 
void get_path(int *path); 
void init();
double get_fitness(int *path);  //计算适应度-长度 
void copy(int *a,int *b,int num=n);

int main()
{
	init();
	int t=0;
	while(t<T)
	{
		for(int i=0;i<m;i++)
		{
			a[i].fitness=get_fitness(a[i].path);
		}
		sort(a,a+m);
		for(int i=0;i<m/2;i++)
		{
			for(int j=0;j<Ncl;j++)
			{
				copy(a[i].path,b[j].path);
				if(j!=0)//变异 
				{
					int p1=rand()%n,p2=rand()%n;
				    while(p1==p2)p2=rand()%n;
				    swap(b[j].path[p1],b[j].path[p2]);
				}
				
				b[j].fitness=get_fitness(b[j].path);
			}
			sort(b,b+Ncl);
			copy(b[0].path,a[i].path);
			a[i].fitness=b[0].fitness;
		}
		
		for(int i=m/2;i<m;i++)
		{
			get_path(a[i].path);
			a[i].fitness=get_fitness(a[i].path);
		}
		t++;
	}
	sort(a,a+m);
	cout<<"最优路径长度: "<<a[0].fitness<<endl; 
    cout<<"最优路径: ";
    for(int i=0;i<n;i++)
        cout<<a->path[i]<<" ";
    cout<<a->path[0]<<endl;
} 
//随机路径
void get_path(int *path)  
{
	random_shuffle(Path.begin(),Path.end());
	for(int i=0;i<n;i++)
	{
		path[i]=Path[i];
	}
}
//初始化输入 
void init()
{
	double x[maxn],y[maxn];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	//计算距离 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dist[i][j]=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
		}
	}
	srand(1314);//随机种子

	for(int j=0;j<n;j++)
	{
		Path.push_back(j);
	}
	for(int i=0;i<m;i++)
	{
		get_path(a[i].path);
	}
	 
}
//获取路径长
double get_fitness(int *path)
{
	double res=0;
	for(int i=1;i<n;i++)
	{
		res+=dist[path[i-1]][path[i]];
	}
	res+=dist[path[0]][path[n-1]];
	return res;
}
void copy(int *a,int *b,int num)
{
	for(int i=0;i<num;i++)
	{
		b[i]=a[i];
	}
}

