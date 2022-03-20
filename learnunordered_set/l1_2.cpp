//删除3种--erase()-返回删除元素的个数
//1.直接指定
//2.迭代器
//3.迭代器,但没有像set一样的--保护最后一个元素不被删除
/*
补充:
1.也有像set的count(),find()函数,empty()函数
*/
#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> myset{2,4,6,8,10,12};
    myset.erase(2);
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;
    //1.直接删除
    auto re=myset.erase(3);
    cout<< typeid(re).name()<<" "<<re<<endl;//m

    //2.
    auto iter=myset.erase(myset.begin());//删除第一个元素
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;

    //3.
    auto iter2=myset.erase(myset.begin(), myset.end());//直接删除全部
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;
    myset={2,4,6,8,10,12};
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;
    myset.clear();
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;

    //find
    auto search = myset.find(2);
    if(search!=myset.end())
    cout<<"Found"<<*search<<endl;
    else
    cout<<"Not found"<<endl;


}








