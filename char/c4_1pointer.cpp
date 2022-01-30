/**
 * strcat在后面解字符串
 * malloc随机给大小,用free释放malloc给的空间
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    //char *str="hello "
    //后面str 是一個指標，指向的 “Hello “ 是 const char *，不是一個字元陣列， 
    //字元阵列是可能没有'\0'的字串,没有限制的话会发生核心转存的问题
    char str[128]="hello ";
    strcat(str,"world");
    cout<<str<<endl;;;;;//无所谓分号数,因为当成了空语句
    char *s=(char *)malloc(sizeof(char)*32);//用malloc随机赋值大小
    strcat(s,"hello ");
    strcat(s,"world");
    cout<<s<<endl;
    free(s);//用了malloc要记得释放空间
}