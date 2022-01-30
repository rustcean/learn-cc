/**
 * 异常处理让程序沿一条不会出错的路径继续执行；也可能是不得不结束程序，但在结束前做一些必要的工作，
 * 如将内存中的数据写入文件、关闭打开的文件、释放动态分配的内存空间等
*/
#include <iostream>
using namespace std;
int main()
{
    cout<<"1--before try block..."<<endl;
    try
    {
        cout<<"2--Inside try block..."<<endl;
        throw 10;
        cout<<"3--After throw ..."<<endl;
    }
    catch(int i)
    {
        cout<<"4--Incath block1...expection..errcode is.."<<i<<endl;
    }
    catch(const char *s)
    {
        cout<<"5--In catch block1...exception..errcode is.."<<s<<endl;
    }
    cout<<"6--After Catch..."<<endl;
    // double m,n;
    // cin>>m>>n;
    // try{
    // cout<<"before diving."<<endl;
    // if(n==0)
    //   throw -1;//抛出int类型异常
    // else
    //   cout<<m/n<<endl;
    // cout<<"after diving."<<endl;
    // }
    // catch(double d)
    // {
    //     cout<<"catch(double)"<<d<<endl;
    // }
    // catch(int e)
    // {
    //     cout<<"catch(int)"<<e<<endl;
    // }
    // catch(...)//吸收所有错误
    // {
    //     cout<<"catch (...)"<<endl;
    // }
    // cout<<"finished"<<endl;
    // return 0;
}