/*遗传算法--不能保证每次得出最优解--但能收敛
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn=20;
const int maxm=1000;

int n=5;                //城市数量
int M=100;              //遗传个体数量
int T=50;               //遗传代数
int Nnum=50;             //克隆数量 
int dist[maxn][maxn];   //记录城市间距离

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
		for(int i=0;i<M;i++)
		{
			a[i].fitness=get_fitness(a[i].path);
		}
		sort(a,a+M);    //排序
		for(int i=0;i<M/2;i++)
		{
			for(int j=0;j<Nnum;j++)
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
			sort(b,b+Nnum);
			copy(b[0].path,a[i].path);
			a[i].fitness=b[0].fitness;
		}
		
		for(int i=M/2;i<M;i++)
		{
			get_path(a[i].path);
			a[i].fitness=get_fitness(a[i].path);
		}
		t++;
	}
	sort(a,a+M);
	cout<<"最短路径长: "<<a[0].fitness<<endl; 
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
	//计算距离 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
        cin>>dist[i][j];			
		}
	}
	srand(1314);//随机种子

	for(int j=0;j<n;j++)
	{
		Path.push_back(j);
	}
	for(int i=0;i<M;i++)
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

