/**
 * 后缀表达式+栈 
*/
#include <math.h>
#include <iostream>
#include <stack>
using namespace std;
class Calcutor
{
    public:
    Calcutor(){}
    double Run(char e[]);
    void Clear();
    private:
    stack<double>s;
    void Addperand(double value);
    bool Getperand(double &left,double &right);
    void Doperand(char op);
};
void Calcutor::Doperand(char op)
{
    double left,right,value;bool result;
    result=Getperand(left,right);
    if(result == true)
    {
        switch(op)
        {
            case '+':value=left+right;s.push(value);break;
            case '-':value=left-right;s.push(value);break;
            case '*':value=left*right;s.push(value);break;
            case '/':if(right==0.0)
                {
                    cerr<<"Divide by 0!"<<endl;
                    break;    
                }
        }
    }
    else Clear();
}

bool Calcutor::Getperand(double &left,double &right)
{
    if(s.empty()==true)
    {cerr<<"缺少右操作数!"<<endl;return false;}
    s.pop();                            //取右操作数
    if(s.empty()==true)
    {cerr<<"缺少左操作数！"<<endl;return false;}
    s.pop();
    return true;

}
void Calcutor::Addperand(double value)
{
    s.push(value);
}
double Calcutor::Run(char e[])
{
    char ch; double newperand,result;int i=0;
    ch=e[i++];
    while(ch!='#')
    {
        switch(ch)
        {
            case '+':
            case '-':
            case '*':
            case '/': Doperand(ch);break;
            default: 
                newperand=(double)ch-'0';
                Addperand(newperand);
        }
        ch=e[i++];
    }
    return result;
}
//清栈
void Calcutor::Clear()
{
    while(!s.empty())
        s.pop();
}






