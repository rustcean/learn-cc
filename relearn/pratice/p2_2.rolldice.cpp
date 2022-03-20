/*rand函数:
*虽然在本程序中每一个rand函数的值都不一样,,但在每一次执行程序时,输出的值不变
*srand来初始化,保证每次执行都不一样
*－rand()%6 ：即指定範圍需要由起始數開始取6個數值，包括起始數
*－rand()%6+2：+2 的意思是指定起始數是2，然後由2開始取六個數作為range(包括2)
                若沒有+2，起始數預設是0。
*/
//
/*这是掷骰子游戏,但不正常
*/
#include <iostream>//看着不准确
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