//cin.get()不能是string型数据
//cin.getline(arrayname,size,s)当遇到s时会结束输入,并把s从缓冲去中删除
//cin.get(arrayname,size,s)当遇到s时会结束输入,但不会删除缓冲去的s
#include <iostream>
using namespace std;
int main()
{
    // char a,b;
    // cin.get(a);
    // b=cin.get();//会吸收entenr建
    // cout<<int(a)<<" "<<int(b)<<endl;
    // return 0;


    // int i;
    // char e[10];
    // cin.get(e,8,' ');//连回车也会吸收
    // cout<<e<<endl;
    // return 0;
    
    // char stu[5][10];
    // int i;
    // for(i=0;i<5;i++)
    // cin.getline(stu[i],10,',');//遇到','才会停止
    // for(i=0;i<5;i++)
    // cout<<stu[i]<<endl; 

    char c;
    char a[50]="this is a string..";
    cout<<"use get() input:";
    while((c=cin.get())!='\n')
    {
        cout.put(c);
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(a,20).put('\n');
        cout<<"look"<<"\t here!"<<endl;
    }



}