//深度优先
#include <iostream>
#include <vector>
#include <cmath>

using std::pow;
using std::cout;
using std::endl;
using std::vector;

int n;
vector<int>vec;

//函数是干嘛的
int get_left(vector<int>avec)
{
    int left=0;
    for(int i=0;i<n;i++)
    {
        left=left+avec[i]*pow(10,i);
    }
    return left;
}

int get_right(vector<int>avec)
{
    int right=0;
    for(int i=0;i<n;i++)
    {
        right=right+pow(avec[i],n);
    }
    return right;
}

void show(vector<int>avec)
{
    vector<int>::const_iterator cit; //这是啥东西?
    for(cit=avec.begin();cit!=avec.end();cit++)
        cout<<*cit<<"\t";
    cout<<endl;
}

vector<int> init(int n)
{
    vector<int> avec(n,0);//这是啥意思
    return avec;
}

void dfs(int step)
{
    if(step==n)
    {
        int left=get_left(vec);
        int right=get_right(vec);

        if(left==right && left>=pow(10,n-1))
        {
            cout<<left<<"\t";
            return ;
        }
    }

    for(int i=0;i<=9;i++)
    {
        if(step<n)//计算美味数字不重复时，条件改为
        {
            vec[step]=i;
            dfs(step+1);
            vec[step]=0;
        }
    }
}

int main()
{
    std::cin>>n;
    vec=init(n);

    show(vec);

    dfs(0);
    cout<<endl;
    return 0;
}
