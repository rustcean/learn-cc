#include <iostream>
#include <cstdlib>
using namespace std;
int rolldice(unsigned );
int main()
{
    int flag;
    unsigned seed;//随机种子
    cout<<"开始游戏:"<<endl;
    cin>>seed;//输入种子
    int sum=rolldice(seed);
    int selfdim;
    switch(sum)
    {
        case 7:
        case 11:flag=1;break;
        case 2:
        case 3:
        case 12:flag=2;break;
        default:flag=0;selfdim=sum;break;
    }
    while(flag==0)
    {
        sum=rolldice(seed);
        if(sum==selfdim)
        {
            flag=1;
        }
        else if(sum==7)
          flag=2;
    }
    if(flag==1)
      cout<<"play win\n";
    else 
      cout<<"player loses\n";
    return 0;
}
int rolldice(unsigned seed)
{
    int sum=0;
    srand(seed);//对rand函数进行初始化  
    int dim1=rand()%6+1;//输出乱数
    int dim2=rand()%6+1;//输出乱数
    sum=dim1+dim2;//
    cout<<"sum= "<<dim1<<"+"<<dim2<<endl;
    return sum;
}