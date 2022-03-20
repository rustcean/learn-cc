//编译:g++ file.cpp -o file--无需添加多的参数
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> myset={3,1};
    myset.insert(6);
    myset.insert(2);
    myset.insert(1);
    myset.insert(3);
    myset.insert(3);
    
    //法1:看不懂的方法--range-based for loop遍历
    for(const auto &s:myset)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    //从结果看--set会自动排序,同时去重

    //法2:迭代器
    for(set<int>::iterator it = myset.begin();it!=myset.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //从后往前:
    for(set<int>::reverse_iterator it=myset.rbegin();it!=myset.rend();it++)
    {
        cout<<*it<<" ";
    }
    //注意:!!! 不可以用iteator it =end()开始,会得到无序的内容
    return 0;
}