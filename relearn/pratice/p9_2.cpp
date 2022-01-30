//一次throw只能丢出一个值--不是?
//catch的运行可能比其他的函数快,也就是说,类似于中断 

#include <iostream>
using namespace std;
int main()
{
    cout<<"1--before try block..."<<endl;
    try
    {
        cout<<"2--Inside try block..."<<endl;
        
        throw (10.01);
        throw 10;//慢丢的没有反应--没有用?不执行?
        cout<<"3--After try block..."<<endl;//以下没有执行
        cout<<"2"<<endl;
        cout<<"s"<<endl;
        cout<<"s"<<endl;
        cout<<"3--After try block..."<<endl;
        cout<<"2"<<endl;
        cout<<"s"<<endl;
        cout<<"s"<<endl;
    }
    catch(double i)
    {cout<<"4--In catch block1..an double type is..."<<i<<endl;}
    catch(int a)
    {cout<<"5--In catch block...an int type is..."<<a<<endl;}
    //  catch(...)//必须放在所有catch的最后
    // {cout<<"6.anything "<<endl<<endl;}
    cout<<"7--After Catch..."<<endl;
    return 0;
    
}