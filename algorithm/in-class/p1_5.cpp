//ZOJ1067
#include <iostream>
using namespace std;

struct C
{
    int red,green,blue;
}c[16];

int distan(struct C a1,struct C a2)
{
    int re=(a1.red-a2.red)*(a1.red-a2.red);
    return re;
}

int main()
{
    struct C a1,a2;
    cin>>a1.red>>a1.green>>a1.blue;
    cin>>a2.red>>a2.green>>a2.blue;
    int r=distan(a1,a2);
    cout<<r<<endl;
}


//分类排序--平均下速度快
//c里面有相关的算法,

//作业:http://poj.org
//2503--北京大学
//二分方法--(查找函数是有的)
//1831?