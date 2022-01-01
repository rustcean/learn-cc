#include <iostream>
#include <cstring>
using namespace std;
class String
{
    public:
    String(){p=NULL;}
    String(char*str);//char指针
    friend bool operator>(String&string1,String &string2);
    friend bool operator<(String&string1,String &string2);
    friend bool operator==(String&string1,String &string2); 
    friend ostream& operator<<(ostream&out,String &str);
    private:
    char const *p;//char指针
};
//有参数的构造函数
String::String(char*str){p=str;}
//输出流重载
ostream& operator<<(ostream&out,String &str)
{
    out<<str.p;
    return out;
}
//大于号重载
bool operator>(String&string1,String &string2)
{
    if(strcmp(string1.p,string2.p)>0)
    return true;
    else return false;
}
//小于号重载
bool operator<(String&string1,String &string2)
{
    if(strcmp(string1.p,string2.p)<0)
    return true;
    else return false;
}
//等于于号重载
bool operator==(String&string1,String &string2)
{
    if(strcmp(string1.p,string2.p)==0)
    return true;
    else return false;
}
//compare函数定义,比较大小
void compare(String &string1,String &string2)
{
    if(operator>(string1,string2)==1)
    {cout<<string1<<">"<<string2;}
    else if(operator<(string1,string2)==1)
    {cout<<string1<<"<"<<string2;}
    else
    {cout<<string1<<"=="<<string2;}
    cout<<endl;
}
int main()
{
    String string1("Hello"),string2("Book"),
           string3("Computer"),string4("Hello");
    //着些都是当成了string类
    compare(string1,string2);
    compare(string2,string3);
    compare(string1,string4);
    return 0;
}