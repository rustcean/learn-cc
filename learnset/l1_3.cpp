//判断元素是否存在
//1.count函数,存在返回1,否则返回0
//2.find函数 返回指向该元素的iterator,
//判断数组是否为空,返回值应该是bool类型

/*
补充:
set与vector不同在:1.set元素是唯一的
2.vector可以修改元素的值,set里的元素的值不可修
3.set是有序的,vector不是
*/
#include <iostream>
#include <set>
using namespace std;
int main()
{
    //1.myset.count()
    set<int> myset={2,4,6,7};
    cout<<myset.count(4)<<endl;

    set<char> myset2={'a','b','c'};
    for(const auto s:myset2)
    {
        cout<<s;
    }
    cout<<endl;
    cout<<myset2.count('a')<<endl;
    //2.myset.find()
    auto search=myset.find(2);
    if(search!=myset.end())
    {
        cout<<"Found "<<*search<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    cout<<*myset.end()<<endl;

    set<string> myset3={"Tom","Jack","John"};
    string key="Tom";
    auto search2=myset3.find(key);
    if(search2!=myset3.end())
    {
        cout<<"Found "<<*search2<<endl;
    }
    else
    {cout<<"Not found"<<endl;}

    //判断数组是否为空
    auto re=myset.empty();
    cout<<re<<typeid(re).name()<<endl;//0 b bool?
    return 0;
}


