/**这是一个关于分数运算的类,不过功能不完善,***************/
/**无法弄出负数和0的情况和分子是分母整数倍是直接写成整数的情况**/

#include <iostream>
using namespace std;
//全局函数-找出最小公倍数
int get_LCM(int a1,int a2)
{
    int m=a1>a2?a1:a2;//least commont mul
    while(1)
    {
        if(m%a1==0&&m%a2==0)
        {
            return m;
        }
        else ++m;
    }
}
//全局函数-找出最大公约数
int get_GCD(int a1,int a2)
{
    int g=a1<a2?a1:a2;
    while(g>0)
    {
        if(a1%g==0&&a2%g==0)
        {return g;}
        else --g;
    }
    return 0;
}
//分数类的声明
class Mark
{
    public:
    Mark(){deno=0;mol=0;}//默认构造函数
    Mark(int m,int d):mol(m),deno(d){}//有参数的构造函数
    Mark chagre(Mark &m);//判断分数是否合理
    Mark simplify(Mark&m);//化简
    Mark operator+(Mark&m);//加号重载
    Mark operator-(Mark&m);//减号重载
    Mark operator*(Mark&m);//乘号重载
    Mark operator/(Mark&m);//除号重载
    friend bool operator>(Mark&m1,Mark&m2);//大于号重载
    friend bool operator<(Mark&m1,Mark&m2);//小于号重载
    friend bool operator==(Mark&m1,Mark&m2);//等于号重载
    friend ostream& operator<<(ostream &o, Mark &re);//输入流重载
    friend istream& operator>>(istream &in, Mark &re);//输入流重载
    private:
    int mol;//分子
    int deno;//分母
};

//判断分数格式是否合理,合理就输出
Mark Mark::chagre(Mark &m)
{
    if(m.deno==0)
    {
        cout<<"error denominator shouldn't be zero!"<<endl;
        exit(0);
    }
    else if(m.mol==0)
    {
        Mark re(0,0);//这个得等等换成类型转换
        return re;
    }
    else 
    {
        Mark re=m;
        if(re.deno<0&&re.mol<0)//负负得正
        {
            re.deno=-re.deno;
            re.mol=-re.mol;
        }
        re=simplify(re);//等于号已经默认重载,不需要自己重载
        return re;
    }
}
// 化简转化函数,用来对结果进行化简为最简形式
Mark Mark::simplify(Mark&m)
{
    Mark re;
    re.deno=m.deno;
    re.mol=m.mol;
    int g=get_GCD(re.deno,re.mol);//找出加后的最大公约数
    re.deno=re.deno/g;//分母化简
    re.mol=re.mol/g;//分子化简
    return re;  
}
//加号重载的定义
Mark Mark::operator+(Mark&m)
{
    Mark re;
    re.deno=get_LCM(m.deno,deno);//找出公倍数
    int a1=re.deno/m.deno;//找m的倍数
    int a2=re.deno/deno;//找基数的倍数
    re.mol=m.mol*a1+mol*a2;//通过倍数相加
    re=chagre(re);
    return re;
}
//减号重载的定义
Mark Mark::operator-(Mark&m)
{
    Mark re;
    re.deno=get_LCM(m.deno,deno);//通分
    int a1=re.deno/m.deno;//找m的倍数
    int a2=re.deno/deno;//找基数的倍数
    re.mol=mol*a2-m.mol*a1;//通过倍数相减得出结果的分子
    re=chagre(re);
    return re;
}
//乘号重载
Mark Mark::operator*(Mark&m)
{
    Mark re;
    re.deno=deno*m.deno;
    re.mol=mol*m.mol;
    re=chagre(re);
    return re;
}
//除号重载
Mark Mark::operator/(Mark&m)
{
    Mark re;
    re.mol=mol*m.deno;//反过来相乘
    re.deno=deno*m.mol;//反过来相乘
    re=chagre(re);
    return re;
}
//大于号重载
bool operator>(Mark&m1,Mark&m2)
{
    double m1d=(double)m1.deno;
    double m2d=(double)m2.deno;
    double m1m=(double)m1.mol;
    double m2m=(double)m2.mol;
    if((m1m/m1d)>(m2m/m2d))return true;
    else return false;
}
//小于号重载
bool operator<(Mark&m1,Mark&m2)
{
    double m1d=(double)m1.deno;
    double m2d=(double)m2.deno;
    double m1m=(double)m1.mol;
    double m2m=(double)m2.mol;
    if((m1m/m1d)<(m2m/m2d))return true;
    else return false;
}
//小于号重载
bool operator==(Mark&m1,Mark&m2)
{
    double m1d=(double)m1.deno;
    double m2d=(double)m2.deno;
    double m1m=(double)m1.mol;
    double m2m=(double)m2.mol;
    if((m1m/m1d)==(m2m/m2d))return true;
    else return false;
}
//输入流重载
ostream& operator<<(ostream &out, Mark &m)
    {
        if(m.mol==0&&m.deno==0)
        {out<<0<<endl;}
        else if(m.mol%m.deno==0)
        {out<<m.mol/m.deno;return out;}
        else 
        {
            out<<"("<<m.mol<<"/"<<m.deno<<")";
        }
        return out;
    }
//输入流重载
istream& operator>>(istream &in, Mark &m)
    {
        cout<<"input molecule: ";
        in>>m.mol;
        cout<<"input denominator:";
        in>>m.deno;
        return in;
    }

int main()
{
    Mark m1(2,3);
    Mark m2;
    cin>>m2;
    cout<<m1<<"*"<<m2<<"=";
    Mark m3=m1*m2;
    cout<<m3<<endl;
    m3=m1/m2;
    cout<<m1<<"/"<<m2<<"=";
    cout<<m3<<endl;
    m3=m1+m2;
    cout<<m1<<"+"<<m2<<"=";
    cout<<m3<<endl;
    m3=m1-m2;
    cout<<m1<<"-"<<m2<<"=";
    cout<<m3<<endl;
    // cout<<m1<<"*"<<m2<<"="<<m1*m2<<endl;//没办法弄,不理解
    // cout<<m1<<"/"<<m2<<"="<<m1/m2<<endl;
    // cout<<m1<<"+"<<m2<<"="<<m1+m2<<endl;
    // cout<<m1<<"-"<<m2<<"="<<m1-m2<<endl;
    return 0;
}

/*display函数,用于对对象的输出*/
    // void Display()//将分数输出
    // {
    //     cout<<mol<<"/"<<deno<<endl;
    // }
    // void get_value()//对分数进行输入
    // {
    //     cout<<"input molecule: ";
    //     cin>>mol;
    //     cout<<"input denominator:";
    //     cin>>deno;
    // }

