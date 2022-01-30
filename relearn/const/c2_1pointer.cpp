#include <iostream>
using namespace std;
const char x='5';//
char y='2';
const char * p1;//指向const对象的指针,指向性可变,值不变
char const *p2;//同上
char * const p3=&y;//const指针指向性不变,值可变
const char *const p4=&x;//指向const对象的const指针,指向性不变,值不变
//const 在 * 左侧,则const修饰变量 const在 * 右侧则const修饰指针本身
int main()
{
    p1=&x;//因为x是const常量,不可变
    cout<<*p1<<endl;
    p1=&y;
    cout<<*p1<<endl;

    cout<<*p3<<endl;
    *p3+=3;
    cout<<*p3<<endl;
    
    cout<<*p4<<endl;
    
    return 0;
}