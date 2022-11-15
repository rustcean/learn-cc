#ifndef TIME_H
#define TIME_H

class Time
{
    int hour;
    int minute;
    int second;
    public:
    Time();
    Time(int h,int m,int s);
    ~Time();
    
    int getH();
    int getM();
    int getS();
    
    void setT(int h,int m,int s);
    void Set();

    void Print();
    void add(Time &t);
    void minus(Time &t);
};

#endif