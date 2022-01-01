#include <unistd.h> 
#include <iostream>
using namespace std;
class CTime
{
	public:
		CTime(int h=0,int m=0,int s=0)
		{
			hour=h;
			minute=m;
			sec=s;
		}
		void Display();//展示
		void SetHour(int h);
		void SetMinute(int m);
		void SetSecond(int s);
		CTime operator++()
		{		
			sec++;
            return CTime(hour, minute,sec);
		}
		void chan();	
        ~CTime(){}
    private:
    int hour;
    int minute;
    int sec;		
}; 
void CTime::Display()
{
	cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
 
void CTime::chan()
{
	if(sec>60)
	{
		sec-=60;
		minute+=1;
	}
	if(minute>60)
	{
		minute-=60;
		hour+=1;
	}
    if(hour>24)hour=0;
}

void CTime::SetHour(int h)
{
	hour=h;
}
void CTime::SetMinute(int m)
{
	minute=m;
}
void CTime::SetSecond(int s)
{
	sec=s;
}


int main() {
	CTime t1(0,0,0);
    while(1)
	{
		++t1;
        t1.chan();
		sleep(1);
		t1.Display();
	}
	return 0;
}