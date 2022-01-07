#include <iostream>
#include <string>
using namespace std;
class Travel
{
    string departure;//出发地
    string aim;//目的地
    int length;//距离
    float P_money;//准备资金
    float e_money;//总花费资金
    string project[11];//消费项目
    float money[11];//消费项目对应消费资金
    int ch;//用来记录消费项目数
    public:
    Travel(string d,string a,int l,float p);
    void set_project();//设置消费项目和资金
    void charge();//判断消费资金总额是否大于准备的资金
    Travel operator=(Travel t);//重载=
    Travel operator||(Travel t);//重载||
    friend ostream & operator<<(ostream &out,Travel t);//重载输出流
    void set();//设置总的其他
    ~Travel(){cout<<"called"<<endl;}
};
Travel::Travel(string d,string a,int l,float p)
{
    departure=d;
    aim=a;
    length=l;
    P_money=p;
    project[0]="0";
    money[0]=0;
    e_money=0;
}
void Travel::set_project()
{
    cout<<"请输入你要花费的项目数,请注意不要超出10个:";
    cin>>ch;
    for(int i=1;i<=ch;i++)
    {
        cout<<"请输入项目名称:";
        cin>>project[i];
        cout<<"请输入项目所花费的金额:";
        cin>>money[i];
        e_money+=money[i];
    }
    cout<<"输入完成"<<endl;
}
void Travel::charge()
{
    if(e_money>P_money)
    cout<<"准备资金不足"<<endl;
    if(e_money<=P_money)
    cout<<"准备资金足够"<<endl;
}

Travel Travel::operator=(Travel t)
{
    departure=t.departure;
    aim=t.aim;
    length=t.length;
    P_money=t.P_money;
    e_money=t.e_money;
    for(int i=0;i<11;i++)
    {
        money[i]=t.money[i];
        project[i]=t.project[i];
    }
    ch=t.ch;
    return t;
}
ostream & operator<<(ostream &out,Travel t)
{
    cout<<"出发地:"<<t.departure<<endl;
    cout<<"目的地:"<<t.aim<<endl;
    cout<<"准备金额:"<<t.P_money<<endl;
    cout<<"距离:"<<t.length<<endl;
    for(int i=1;i<=t.ch;i++)
    {
        cout<<"项目"<<i<<"是:"<<t.project[i]<<endl;
        cout<<"消费:"<<t.money[i]<<"元"<<endl;
    }
    cout<<"共将消费:"<<t.e_money<<endl;
    return out;
}

void Travel::set()
{
    cout<<"请输入目的地:";
    cin>>this->aim;
    cout<<"请输入出发地:";
    cin>>this->departure;
    cout<<"请输入距离(单位:km):";
    cin>>this->length;
    cout<<"请输入准备金额(单位:元):";
    cin>>this->P_money;
    cout<<"是否输入详细消费计划:1(no)/2(yes):";
    int i;cin>>i;
    if(i==1)cout<<"输入完成!"<<endl;
    else if(i==2)set_project();
    else cout<<"输入出错";
}
//主函数
int main()
{
    Travel t1("北京","上海",1600,100);
    t1.charge();
    cout<<endl;
    t1.set();
    t1.charge();
    cout<<endl;
    Travel t2=t1;
    cout<<t2;
    
}

