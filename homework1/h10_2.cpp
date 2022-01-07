#include <iostream>
#include <string>
using namespace std;
class Elect
{
    char *cla;       //种类
    string brand;
    float power;
    int life;
    public:
    Elect(char *c,string b,float p,int l);
    ~Elect(){cout<<"Elect called"<<endl;}
    virtual void display()const;
    virtual string getbrand()const;
    float getpower()const;
    int getlife()const;
    void setbrand(string b);
    void setpower(float p);
    void setlife(int l);
};
Elect::Elect(char *c,string b,float p,int l)
{
    cla=c;
    brand=b;
    power=p;
    life=l;
}
void Elect::display()const
{
    cout<<"\t种类\t品牌\t功率\t使用时长\n";
    cout<<"\t";
    for(int i=0;cla[i]!='\0';i++)
    cout<<cla[i];
    cout<<"\t"<<brand<<"\t"<<power<<"\t"<<life<<"年"<<endl;
}
string Elect::getbrand()const{ return brand;}
float Elect::getpower()const{return power;}
int Elect::getlife()const{return life;}
void Elect::setbrand(string  b){brand=b;}
void Elect::setpower(float p){power=p;}
void Elect::setlife(int l){life=l;}

//子类
class Acondition:public Elect
{
    float temperlature;
    string model;
    char *company;
    public:
    Acondition(string b,float p,int l,float t,string m,char *com);
    ~Acondition(){cout<<"Acnoditioner called"<<endl;}
    virtual void display()const;
    
};
Acondition::Acondition(string b,float p,int l,float t,string m,char *com)
:Elect("空调",b,p,l)
{
    temperlature=t;
    model=m;
    company=com;    
}
void Acondition::display()const
{
    cout<<"空调:"<<endl;
    cout<<"\t工作温度\t型号\t公司\t寿命"<<endl;
    cout<<"\t"<<temperlature<<"\t"<<model<<"\t";
    for(int i=0;company[i]!='\0';i++)
    cout<<company[i];
    cout<<"\t"<<getlife()<<"年"<<endl;
}

int main()
{
    Elect e("空调","美的",5000,10);
    e.display();
    cout<<endl;
    cout<<e.getbrand()<<endl;
    e.setbrand("红米");
    cout<<e.getbrand()<<endl;
    cout<<e.getpower()<<endl;
    e.setpower(2000);
    cout<<e.getpower()<<endl;
    cout<<e.getlife()<<endl;
    e.setlife(20);
    cout<<e.getlife()<<endl<<endl   ;
    Acondition a("美的",5000,10,37.5,"2021-12-31型","美的");
    a.display();
    cout<<endl<<endl;
    return 0;
}