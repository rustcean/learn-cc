
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[30],visit[30];//每个测试例子都是小于30的
bool flag; //判断是否有解

void DFS(int start,int depth,int sum) //深度优先
{
    if(depth==0) //到底
    {
        for(int i=start;i<n&&sum>=a[i];i++)
        {
            //sum要比a[i]大才可以继续，一个一个往前算
            if(sum==a[i])//如果有解
            {
                flag=true;//有解
                for(int j=0;j<i;j++)//从前面往后输出结果
                {
                    if(visit[j])//是等式的组成部分才可以输出
                    {
                        if(sum==a[j])
                        //说明a[j]是等式左边最后一个加数
                            cout<<a[j]<<"="<<a[i]<<endl;
                        else cout<<a[j]<<"+";
                        sum-=a[j];//减去
                    }
                }
            }
        }
    }

    else
    {
        for(int i=start;i<n;i++)
        {
            if(sum+a[i]<=a[n-1])
            {
                
                sum+=a[i];
                visit[i]=1;//记录
                --depth;//已经记录了一个数，于是长度减1
                DFS(i+1,depth,sum);
                sum-=a[i];//回来要重新减去，避免影响结果
                visit[i]=0;//同样的要将数组的记录抹除，
                ++depth;//回来长度加1
                
            }
        }
    }
}


int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);//排序后面才可以一步一步往后计算
        memset(visit,0,sizeof(int)*30);//置0
        flag=false;//初始为false
        for(int i=2;i<n;i++)
            DFS(0,i,0);//深度范围从2开始
        if(!flag)//若无解，便输出
            cout<<"Can't find any equations."<<endl<<endl;
        else cout<<endl;
    }
    return 0;
}