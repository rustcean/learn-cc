/*自己制作的比较大小小程序:
*输入一个数字,系统会自己生成一个数字,二者比较大小,得出结果
*顺便,先输出rand函数最大值
*顺便,输出掷骰子,会自动生成一个1~6的数字
*/

#include <iostream>
#include <cstdlib>
using namespace std;
int charge_wei(double);//判断函数,判断位数
int rolldice(int);//根据位数,生成随机数字,
int main()
{
    //最大数
    cout<<"rand最大的数:";
    cout<<RAND_MAX<<endl<<endl;
    //骰子掷
    cout<<rand()%5+1<<endl;
    //小程序
    unsigned seed;//种子
    seed=(unsigned)time(NULL);//取得时间序列
    srand(seed);//以时间序列当乱数种子
    double ch1;//用来输入
    cout<<"游戏开始,输入一个数"<<endl;
    cin>>ch1;
    int ch2=rolldice(charge_wei(ch1));
    cout<<"机器结果:"<<ch2<<endl;
    if(ch1>ch2)
    cout<<"player win!"<<endl;
    else if(ch1==ch2)
     cout<<"no one win"<<endl;
    else 
    cout<<"player loses"<<endl;
}

int charge_wei(double ch)
{
    int wei=1;
    int c=ch;
    for(;c>10;)
    {
        c=c/10;
        wei++;
    }
    return wei;
}

int rolldice(int a)
{
    int result=rand()%9;//没有+1所以可以从0开始
    a-=1;//上面已经有一位,所以减1
    while(a--)
    {
        result*=10;
        int dim1=rand()%9+1;//输出乱数
        result+=dim1;
    }
    return result;
}