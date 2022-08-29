/*
本代码用来计算不会重复的单词,利用set的不重复性和sstream的函数
*/
#include <sstream>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;


//输入string类型的字符串，返回字符数
int counter(string str)
{
    string word;//暂存str的单词
    istringstream stream(str);
    set<string>Set;//定义集合Set
    while(stream>>word)
    {
        Set.insert(word);
    }
    return Set.size();//返回大小
}


int main()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="#")
            break;
        int num=counter(str);
        cout<<num;
    }
    return 0;
}
