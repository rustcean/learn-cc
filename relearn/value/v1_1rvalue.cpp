#include <iostream>
using namespace std;
int getdata(int &&num);
int main()
{
    int num=1;
    int *pnum=&num;
    int *&rnum=pnum;//rnum是num的别名
    //int * &rnum = &num1;//这是不允许的  无法从“int *”转换为“int *&”        
    cout<<*rnum<<endl;
    //要想绑定一个左值到右值引用，通常需要std::move()将左值强制转换为右值
    int &&r1=std::move(num);
    cout<<r1<<endl;
    //常量左值可以引用右值
    const int &num2=2;
    cout<<num2<<endl;
    //右值的引用一般为 int *&&num=&num1;
    
    int &&r2=num+1;
    int r3=num+1;
    int *&&r4=&num;
    cout<<r2<<endl;
    cout<<r3<<endl;
    cout<<*r4<<endl;
    //函数形式
    cout<<getdata(num+1)<<endl;;

    return 0;
}
int getdata(int &&num)
    {
        cout<<num;
        num+=1;
        return num;
    }
/**
 * 右值引用在你需要使用寄存器中的值的时候可以进行右值引用。寄存器的刷新速度很快，
 * 没有右值引用的话就需要将寄存器中的值拷贝到内存中，在进行使用，这是很浪费时间的。
*/