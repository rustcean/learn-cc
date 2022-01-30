#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char ch;

    ofstream outfile("/home/wnanqun/nanqun/learn-c++/fiostream/003",ios::binary);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        abort();//什么函数c
    }
//第一部分
    ifstream infile1("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::binary);
    if(!infile1)
    {
        cerr<<"open error!"<<endl;
        abort();
    }
    while(infile1.get(ch))
    {
        outfile.put(ch);
    }
    cout<<endl;
    infile1.close();

//第二部分
    ifstream infile2("/home/wnanqun/nanqun/learn-c++/fiostream/002",ios::binary);
    if(!infile2)
    {
        cerr<<"open error!"<<endl;
        abort();
    }
    outfile.seekp(-10,ios::end);
    while(infile2.get(ch))
    {
        outfile.put(ch);
    }
    cout<<endl;
    infile2.close();
}