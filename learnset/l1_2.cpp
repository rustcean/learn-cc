//set删除指定元素使用erase()--三种用法
//清空 clear()
//判断元素是否存在:1.count()-存在返回1,否则0. 
//2.find()有就返回指定严肃的的iterator否则返回 past-the-end (end()) iterator
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set <int> myset{2,3,3,4,6,8};
    //1.直接删除某个元素--返回删除元素的个数--删除不存在的元素--返回0
    myset.erase(3);//返回值可以不管
    for(const auto &s:myset)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    auto ret=myset.erase(2);//auto是啥?--自动判断数据类型
    cout<<ret<<endl;
    cout<<ret<<typeid(ret).name()<<endl;//m--长整型
    for(const auto &s:myset)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    
    //2.--返回值是迭代器
    set<int>::iterator iter=myset.erase(myset.begin());
    //删除第一个元素
    for(const auto &s:myset)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<*iter<<" "<<typeid(ret).name()<<endl;//是 m 
    
    //3.--返回迭代器
    set<int>::iterator iter2=myset.erase(myset.begin(),--myset.end());
    //删除元素,到最后一个(不删),
    cout<<"size: "<<myset.size()<<endl;
    myset.clear();//清空
    for(const auto &s:myset)
    {
        cout<<s<<" ";
    }
    cout<<endl;


}


















