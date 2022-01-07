#include <iostream>//二维数组输入实现多句子输入
using namespace std;
#define NUM 10
void input(char (*p)[20],int num)//input 
{
    for(int i=0;i<num;i++)
    cin.get(*(*(p+i)+20));
}
void out(char (*p)[20],int num)
{
    for(int i=0;i<num;i++)
    cout<<*(*(p+i)+20)<<" ";
}    
//int charge(char )
int main()
{
    char a[NUM][20];
    input(a,NUM);
    out(a,NUM);
    return 0;
}