#include <iostream>
using namespace std;
class Elevator 
{
    public:
    Elevator();
    Elevator(int f,int y):floor(f),yuan(y){}
    void anniu();//按钮用来确定是否搭乘电梯
    void in();//进入电梯按楼层用
    void goon();//中间
    void get();//到达
    void ask();//小实验,询问的
    void rein();
    ~Elevator()
    {cout<<"结束"<<endl;}
    private:
    int yuan;//原来的楼层
    int floor;//想去的楼层

};

Elevator::Elevator()
{
    floor=1;
    yuan=1;
}

void Elevator::anniu()
{
    cout<<"Do you want to take Elevator?"<<endl;
    cout<<"If yes please input 1,if no please input 2 : ";
    int a;
    cin>>a;
    if (a==1){in();}
    else if(a==2){cout<<"ok goodbye."<<endl;}
    else { cout<<"error,gameover"<<endl;}

}

void Elevator::in()
{
    cout<<"welcome "<<endl;
    cout<<"you are in floor "<<yuan<<endl;
    cout<<"Which floor do you want to go : ";
    cin>>floor;
    if(floor>=1&&floor<=15)
    {
    cout<<"please wait..."<<endl;
    goon();
    }
    else {cout<<"error"<<endl;floor=yuan;}
}

void Elevator::goon()
{
    if(yuan<=floor)
    {
        for(int i=yuan;i<=floor;i++)
        {
        cout<<"now is floor "<<i<<endl;
        int j=1000000000;
        while(j){j--;}
        }
    }
    else if(yuan>floor)
    {
        for(int i=yuan;i>=floor;i--)
       {
        cout<<"now is floor "<<i<<endl;
        int j=1000000000;
        while(j){j--;}
        }
    }
get();
}

void Elevator::get()
{
    cout<<"Ok here is floor "<<floor<<endl;
    yuan=floor;//时间不太够,之后自己会在填充一个可以继续搭电梯的函数,本句在此无意义
    rein();
}

void Elevator::rein()
{
    cout<<endl;
    cout<<"now you are in floor "<<yuan<<endl;
    cout<<"do you want to take Elveator ?"<<endl;
    cout<<"If yes please input 1,if no please input 2 : ";
    int a;
    cin>>a;
    if (a==1){in();}
    else if(a==2){cout<<"ok goodbye."<<endl;}
    else { cout<<"error,gameover"<<endl;}
}

void Elevator::ask()
{
    cout<<endl<<endl;
    cout<<"do you want to make a fist floor one ?"<<endl;
    cout<<"if yes input 1. if not input 2 : ";
    int i;
    cin>>i;
    if(i==1)
    {
        cout<<" ok let's begin "<<endl;
        cout<<" input the first floor :";
        cin>>yuan;
        in();
    }
    else if(i==2){cout<<"ok goodbye "<<endl;}
    else cout<<"error,gameover "<<endl;
}
int main()
{
    Elevator e1 ;
    e1.anniu();
    Elevator e2 ;
    e2.ask();
    return 0;
}
