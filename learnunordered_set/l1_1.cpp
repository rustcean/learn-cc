//编译:g++ l1_1.cpp -o l11  无特别参数
//初始化1,直接2,从数组
//插入,insert()函数

#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    //1.直接初始化
    unordered_set<int> myset={1,3,2,5,4};//栈?--反向的
    for(const auto &s:myset)
    {cout<<s<<" ";}
    cout<<endl;
    //2.从c-style阵列初始化,(数组首地址,数组结束地址)
    int arr[]={5,3,2,1,4};
    unordered_set<int> myset2(arr,arr+2);//栈?
    for(const auto &s:myset2)
    {cout<<s<<" ";}
    cout<<endl;

    //插入
    unordered_set<int> myset3={3,1};
    myset3.insert(2);
    myset3.insert(5);
    myset3.insert(5);
    myset3.insert(5);
    for(const auto &s:myset3)
    {cout<<s<<" ";}
    cout<<endl;

    //输出也可以用迭代器
    //注意:因为无序,所以没有像set的反向迭代器
    for(unordered_set<int>::iterator it=myset3.begin();it!=myset3.end();it++)
    {cout<<*it<<" ";}
    cout<<endl;

    //auto关键字
    for(auto it=myset3.begin();it!=myset3.end();it++)
    {cout<<*it<<" ";}
    cout<<endl;
    
    return 0;
}
