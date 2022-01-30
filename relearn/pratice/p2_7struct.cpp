#include <iostream>
using namespace std;
struct student
{
    int num;
    char name[20];
    char gender;
};
int main()
{
    student s={10,"wu",'M'};
    cout<<s.num<<endl;//10
    cout<<sizeof(s.num)<<endl;//4
    cout<<sizeof(s.name)<<endl;//20
    cout<<sizeof(s.gender)<<endl;//1
    cout<<sizeof(s)<<endl;//28
    return 0;    
}
