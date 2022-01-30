#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char ch;
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::out|ios::binary);
    for(int i=0;i<99;i++)//数字
    {
        if(i>0&&(i%30==0))
          outfile.put('\n');
        outfile.put(i);
        outfile<<" ";
    }
    outfile.close();
    ifstream infile("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::in|ios::binary);
    while(infile.get(ch))//读成符号
    {
        cout<<ch;
    }
    infile.close();
    
}