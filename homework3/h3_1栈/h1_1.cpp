/**
 * 中缀表达式
 * 
*/
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Calcutor
{
    public:
    Calcutor(){}
    double Run(string e);
    void Clear();
    private:
    stack<double>s;
    void Addperand(double value);
    bool Getperand(double &left,double &right);
    void Doperand(char op);
};
bool Calcutor::Getperand(double &left,double &right)
{
    if(s.empty()==true)
    {cerr<<"缺少右操作数!"<<endl;return false;}
    left=s.top();
    s.pop();                            //取右操作数
    if(s.empty()==true)
    {cerr<<"缺少左操作数！"<<endl;return false;}
    right=s.top();
    s.pop();
    return true;

}
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
void Calcutor::Addperand(double value)
{
    s.push(value);
}
double Calcutor::Run(string e)
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
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}


//中缀转后缀

int isp(char c)
{
    int re;
    switch(c)
    {
        case '#':re= 0;break;
        case 'c':re= 1;break;
        case '*':case '/':case '%':re= 5;break;
        case '+':case '-':re= 3;break;
        case ')':re= 6;break;
    }
    return re;
}
int icp(char c)
{
    int re;
    switch(c)
    {
        case '#':re= 0;break;
        case 'c':re= 6;break;
        case '*':case '/':case '%':re= 4;break;
        case '+':case '-':re= 2;break;
        case ')':re= 1;break;
    }
    return re;
}

string change(string e)
{
    string result="";
    stack<char>ss;
    char ch; int i=0;
    ch=e[i++];
    ss.push('#');
    while(ch!='#')
    {   
        if(int(ch)>=48 && int(ch)<=57)
            result+=ch;
        else
        {
            if(icp(ch)>isp(ss.top()))
                ss.push(ch);
            else if(icp(ch)<isp(ss.top()))
            {
                result+=ss.top();
                ss.pop();
            }
            else if(icp(ch)==isp(ss.top()))
                ss.pop();
        }
        ch=e[i++];
    }
    while(!ss.empty())
    {
        result+=ss.top();
        ss.pop();
    }
    return result;
}


int main()
{
    string s="2*9+3-2*(5-3)/4#";
    string ss=change(s);
    cout<<ss<<endl;

    // Calcutor ss;
    // string s="123*+#";
    // ss.Run(s);
    // ss.Clear();

}



