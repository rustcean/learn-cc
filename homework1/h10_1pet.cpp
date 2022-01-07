#include <iostream>
#include <string>
using namespace std;
class Pet
{
    string cl;//class
    int age;
    int weight;
    string health;
    public:
    Pet(string,int,int,string);
    void setinfo();
    virtual void display()const;
    void check()const;
    ~Pet(){cout<<cl<<"called"<<endl;}
};
Pet::Pet(string c,int a,int w,string h)
{
    cl=c;
    age=a;
    weight=w;
    health=h;
}
void Pet::setinfo()
{
    cout<<"please input the class of the pet:";
    cin>>cl;
    cout<<"please input the age of the pet:";
    cin>>age;
    cout<<"please input the weight of the pet:";
    cin>>weight;
    cout<<"please input the information of health of the pet:";
    cin>>health;
}
void Pet::display()const
{
    cout<<"class: "<<cl<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"weight: "<<weight<<endl;
    cout<<"health: "<<health<<endl;
}
void Pet::check()const
{
    if(health.compare("健康")==0)
    cout<<"good,keep on"<<endl;
    if(health.compare("一般")==0)
    cout<<"please take good care of it "<<endl;
    if(health.compare("生病")==0)
    cout<<"take it to go to see a doctor please !"<<endl;
}



int main()
{
    Pet p1("狗",2,18,"健康");
    p1.display();
    p1.setinfo();
    p1.check();
    return 0;
}