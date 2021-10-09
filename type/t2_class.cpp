#include <iostream>
using namespace std;
class Student
{
    private:
    int num;
    int score;
    public:
    void setdata()
    {
        cin>>num;
        cin>>score;
    }
    void display()
    {
        cout<<"num = "<<num<<endl;
        cout<<"score = "<<score<<endl;
    };
};
Student studl_1,stdul_2;
int main()
{
    cout<<"input two students' two data xx xx"<<endl;   
    studl_1.setdata();
    stdul_2.setdata();
    studl_1.display();
    stdul_2.display();
    return 0;
}