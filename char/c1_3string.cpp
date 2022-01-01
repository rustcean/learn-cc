#include <iostream>//关于string可以看spicel中的s1
#include <cstring>
using namespace std;
int main()
{
    string str1;
    cout<<"输入cin型：";
    cin>>str1;//不读入换行符和空格
    int i=strlen(str1.c_str());//好意外，竟然要这么测
    cout<<i<<endl;
    cin.clear();//本来是用来清除影响的但是没用
    cin.sync();//用来清除缓存区的数据流,不过我还没能知道怎么用
    cout<<"输入getline型：";
    cin.get();//读去enter
    getline(cin,str1);
    cout<<str1<<endl;
    i=strlen(str1.c_str());
    cout<<"有效长度为"<<i<<endl;



//     char str3[20]="0123456 8";
//     int j=strlen(str3);//对于char型却不用
//     cout<<j<<endl;
//     //测的是字符长度 
//     int k=sizeof(str3);
//     cout<<k<<endl;
//     //测的是数组规格
}