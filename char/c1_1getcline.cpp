#include <iostream>//get是
using namespace std;
int main()
{
 const int arrayLength = 40;
 char name1[arrayLength];
 char name2[arrayLength];
 cout<<"Enter your name1:\n";
 cin.get(name1,arrayLength);//不会读后面的空格使得name2读了空格
//在接下来name2读取的时候输入流就成为空行了，这就导致后面的cin.get()都没有了效果
 cout<<"Enter your name2:\n";
 cin.get(name2,arrayLength);
 cout<<"name1: "<<name1<<endl;
 cout<<"name2: "<<name2<<endl;
 cin.get();
 cin.get();
//解决方法是在读取输入流之前调用cin.clear()方法来恢复输入。
cin.clear();
 char name3[20];
     cout<<"输入一个数"<<endl;
     cin>>name3;//enter符号不会吸收,遇到空格不吸收，可以读字符串
     cin.get();
     cout<<name3<<endl;
     char name4[20]   ;
     cin.getline(name4,20);
     cout<<name4<<endl; //当成变量了？？？？
 return 0;
}