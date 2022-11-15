#include "Time.h"
#include "Park.h"
#include <iostream>
using  namespace std;

//价格判断函数--如需修改规则，可直接在此处修改
int getcharge(int h)
{ return 3*h;  }
//成员函数
//输入函数
void Park::Set()
{
    cout<<"请输入车牌号: "<<endl;
    Car data;
    cin>>data.num;
    data.reach.Set();
    data.leave=data.reach;
    if(park.size()<MaxNUM) //如果车库未满
    {
        park.push(data);
    }
    else                   //如果车库满了
    {
        waite.push(data);
    }
    //system("clear");       //清屏
    cout<<"录入完成"<<endl;
}
//离开函数
void Park::Leave()
{
    cout<<"请输入车牌号: "<<endl;
    Car data;
    cin>>data.num;
    bool flag=Have(data);
    if(!flag)
    {
        cout<<"出错!停车场没有你输入的车牌号的车"<<endl;
        return;
    }
    else 
    {
        data.leave.Set();
        data.leave.minus(park.top().reach);
        int length=data.leave.getH()+1;
        if(data.leave.getM()==0)
            if(data.leave.getS()==0)
                length-=1;
        int money=getcharge(length);

        cout<<"需付款: "<<money<<" 元"<<endl;
        getpop(data);//离开
    }
}
//判断某车牌号是否存在于停车库
bool Park::Have(Car &c)
{
    stack<Car> tmp;
    bool flag=false;
    while(!park.empty())
    {
        if(park.top().num==c.num)
        {
            flag=true;
            break;
        }
        tmp.push(park.top());
        park.pop();
    }
    while(!tmp.empty())        //如果此时候车区有车，就放入
    {
        park.push(tmp.top());
        tmp.pop();
    }   
    return flag;
}
//将某车去除
void Park::getpop(Car &c)
{
    stack<Car> tmp;
    while (!park.empty())
    {
        if(park.top().num==c.num)
        {
            park.pop();  //移除对应信息
            break;
        }
        tmp.push(park.top());
        park.pop();
    }
    while(!tmp.empty())
    {
        park.push(tmp.top());
        tmp.pop();
    }   
    if(!waite.empty())
    {
        park.push(waite.front());
        waite.pop();
    }
}
//输出车库信息
void Park::PrintP()
{
    //system("clear");
    cout<<"停车场状况:"<<endl;
    stack<Car> tmp;
    while(!park.empty())
    {
        cout<<"车牌号: "<<park.top().num<<"\t入库时间:"<<endl;
        park.top().reach.Print();
        tmp.push(park.top());
        park.pop();
    }
    cout<<""<<endl;
    while (!tmp.empty())
    {
        park.push(tmp.top());
        tmp.pop();
    }

}

void Park::PrintW()
{
    //system("clear");
    cout<<"候车区状况:"<<endl;
    queue<Car> temp;
    while (!waite.empty())
    {
        temp.push(waite.front());
        cout<<"车牌号:"<<waite.front().num<<"\t到达时间:"<<endl;
        waite.front().reach.Print();
        waite.pop();
    }
    cout<<""<<endl;
    while(!temp.empty())
    {
        waite.push(temp.front());
        temp.pop();
    }
}

/*
使用:
输入:
来的车:
1.车牌号-时间
如果超出限制转queue 

2.走的车 车牌号-时间 --

输出:
1.当前的车站和候车场的情况-Print()
2.停留时间，要的钱 --charge()

size--获取大小的函数
*/
