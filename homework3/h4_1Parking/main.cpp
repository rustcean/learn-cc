#include "Park.h"
#include "Time.h"
#include <iostream>
#include <string.h>
using namespace std;

//主函数--menu()
void menu(Park &p)
{
    cout<<"<<<<<<<<<<<<>>>>>>>>>>>>>"<<endl;
    cout<<"*****欢迎来到停车场系统*****"<<endl;
    cout<<"*****1.车辆到达登记********"<<endl;
    cout<<"*****2.车辆离开登记********"<<endl;
    cout<<"*****3.查看停车场车辆信息***"<<endl;
    cout<<"*****4.查看候车场车辆信息***"<<endl;
    cout<<"*****0.退出系统************"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请输入对应的编号，执行相应的功能:"<<endl;
    unsigned int ch;
    while(1)
    {
        cin>>ch;
        switch(ch)
        {
            case 1:p.Set();menu(p);break;
            case 2:p.Leave();menu(p);break;
            case 3:p.PrintP();menu(p);break;
            case 4:p.PrintW();menu(p);break;
            case 0:exit(0);break;
        }
    }
}

int main()
{
    Park p;
    menu(p);
    return 0;
}


