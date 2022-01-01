#include <iostream>
#include <array>//
#include <vector> 
using namespace std;
int main()
{
    int a(5);
    cout<<"输入 "<<a<<" 个数字"<<endl;
    vector <int>b(a);
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<a;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;


    vector <int> str1;
    cout<<"输入 "<<a<<" 个数字"<<endl;
    for(int i=0;i<a;i++)
    {
        int x;
        cin>>x;
        str1.push_back(x);
    }
    for(int i=0;i<str1.size();i++)
    {
        cout<<str1[i]<<" ";
    }
    cout<<endl;
    // array <char,3> c1={'a','b','s'};
    // cout<<c1[1]<<endl;

    //vector <char> a2(&c1,&c1+2);/*vector只能由vector赋值，对象还得相同*/
    return 0;
}