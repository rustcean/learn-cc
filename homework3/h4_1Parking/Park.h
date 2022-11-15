#ifndef PARK_H
#define PARK_H
#include "Time.h"
#include <stack>
#include <queue>
#include <string>
#define MaxNUM 3
struct Car
{
    std::string num;   //车牌号--string类会需要std格式--本空间并没有声明
    Time reach;     //到站时间
    Time leave;     //离开时间
};

class Park
{
    public:
    void PrintP(); //输出停车场信息
    void PrintW(); //输出候车场信息
    void Set();    //用来输入数据
    void Leave();  //离开
    private:
    bool Have(Car &c);    //判断是否有Car 
    void getpop(Car &c);  //除去Car
    std::stack<Car> park;
    int MaxSize=MaxNUM;   
    std::queue<Car> waite;
};
#endif
/*
void gettime()
    {
        time_t rawtime;
        struct tm *ptminfo;
        time(&rawtime);
        ptminfo = localtime(&rawtime);
        printf("current: %02d-%02d-%02d %02d:%02d:%02d\n",
        ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);
    }
*/