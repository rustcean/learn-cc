#include <iostream>
#include <fstream>
using namespace std;
/**
 * @brief 加密函数
 * 
 * @param p 输入的数组名
 * @param n 数组大小
 * @return ** void 
 */
void encryption(char *p,int n)
{
    for(int i=0;i<n;i++)
    {
        if((p[i]>='A'&&p[i]<='Z'||(p[i]>='a'&&p[i]<='z')))
        {
        p[i]+=4;
        if(p[i]>'Z'||(p[i]>'z'))
        p[i]-=26;
        }
    }
}
/**
 * @brief 解密函数
 * 
 * @param p 输入的数组名
 * @param n 数组大小
 * @return ** void 
 */
void decrypt(char *p,int n)
{
    for(int i=0;i<n;i++)
    {
        if((p[i]>='A'&&p[i]<='Z'||(p[i]>'a'&&p[i]<'z')))
        {
        p[i]-=4;
        if((p[i]<'A'||p[i]<'a'))
        p[i]+=26;
        }
    }
}
//主函数
int main()
{
    char a[10];
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/homework1/h1033",ios::out|ios::binary);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    cout<<"enter 10 character:";
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    encryption(a,10);//加密
    for(int i=0;i<10;i++)
    {
       outfile<<a[i]<<" ";//输出到文件中
    }
    outfile.close();
    //输出
    ifstream infile("/home/wnanqun/nanqun/learn-c++/homework1/h1033",ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(int i=0;i<10;i++)
    {
        infile>>a[i];
    }
    cout<<"文件内容:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    cout<<"解密:"<<endl;
    decrypt(a,10);
    for(int i=0;i<10;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    
    return 0;
}