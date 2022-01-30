/**
 * @file f1_2infile.cpp
 * @author wnanqun (you@domain.com)
 * @brief 只是一个打开文件的函数infile-display函数-可用
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;
void display(char const *filename)
{
    ifstream infile(filename,ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    char ch;    
    while(infile.get(ch))
    {
        cout.put(ch);  //输出  
    }
    cout<<endl;
    infile.close();
}

int main()
{
    display("/home/wnanqun/nanqun/learn-c++/fiostream/001");
    return 0;
}