#include <iostream>
#define NUM 3
using namespace std;
class Student
{
    public:
    Student operator+(Student &arr);
    void input();
    void show();
    private:
    int array[NUM];
};
//重载"+"用于数组的加法
Student Student::operator+(Student &arr)
{
    Student c;//用来返回赋值
    for(int i=0;i<NUM;i++)
    {
        c.array[i]=array[i]+arr.array[i];
        //对应的元素相加
    }
    return c;
}

void Student::input()
{
    for(int i=0;i<NUM;i++)
    cin>>array[i];
}

void Student::show()//将数组逐一show出来
{
    for(int i=0;i<NUM;i++)
    cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    Student s1;
    cout<<"array s1= ";
    s1.input();
    Student s2;
    cout<<"array s2= ";
    s2.input();
    Student s3=s1+s2;
    cout<<"s1+s2=:";
    s3.show();
}