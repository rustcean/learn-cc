/**
 * @file v1_3.cpp
 * @author your name (you@domain.com)
 * @brief 虚函数是动态绑定的，默认参数是静态绑定的。默认参数的使用需要看指针或者应用本身的类型，而不是对象的类型！
 * 注意:这个与传统的指针的使用很不一样
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream> 
using namespace std; 

class Base 
{ 
    public: 
        virtual void fun ( int x = 10 ) 
        { 
            cout << "Base::fun(), x = " << x << endl; 
        } 
}; 

class Derived : public Base 
{ 
    public: 
        virtual void fun ( int x=20 ) 
        { 
            cout << "Derived::fun(), x = " << x << endl; 
        } 
}; 


int main() 
{ 
    Derived d1; 
    Base *bp = &d1; //指向子类,
    bp->fun();  // 10,输出却是父类的内容
    return 0; 
} 