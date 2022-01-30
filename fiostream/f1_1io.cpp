/**
 * @file f1_1io.cpp
 * @author wnanqun (you@domain.com)
 * @brief in out 练习
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;

void save_to_file()
{   
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/fiostream/001");
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    char c[80];
    cin.getline(c,80);
    for(int i=0;i<80;i++)
    {
        if((c[i]>=65&&c[i]<=90)||(c[i]>=97&&c[i]<=122))//仅提取字母
        {
            outfile.put(c[i]);  
            cout<<c[i]<<" ";
        }
    }
     cout<<endl;
    outfile.close();
}

void get_from_file()
{
    char ch;
    ifstream infile("/home/wnanqun/nanqun/learn-c++/fiostream/001");
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/fiostream/002");
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    while(infile.get(ch))//不断获取字符
    {
        if(ch>=97&&ch<=122)
        ch=ch-32;
        outfile.put(ch);//将该大写字母存入002文件中
        cout<<ch;
    }
    cout<<endl;
    infile.close();
    outfile.close();
}
int main()
{
    save_to_file();
    //调用,输入一行字符串并将其存入001文件中
    get_from_file();
    return 0;
}