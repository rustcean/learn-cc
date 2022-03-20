/*@ wnanqun
*new,struct,[]的运用
*
*/
#include <iostream>
#include <cstring>
using namespace std;
struct Person
{
    double salary;//薪水
    char *name;//姓名
};
class SalaryManage
{
    Person *employ;
    int max;//数组下标
    int n;//实际职工人数
    public:
    SalaryManage(int Max=0)
    {
        max=Max;
        n=0;
        employ=new Person[max];//申请max个Person空间的空间,employ指向
        //!!!这个空间只是1个空间
    }
    double &operator[](const char *Name)
    {
        cout<<"n="<<n<<endl;
        Person *p;
        for(p=employ;p<employ+n;p++)//
         if(strcmp(p->name,Name)==0)//先判断人员是否已经存在,存在则返回薪水
          return p->salary;
        //不存在情况处理
        p=employ+n++;//指针向前移动
        p->name=new char[strlen(Name)+1];//申请, 说明,这个长度可增
        strcpy(p->name,Name);//赋值姓名
        p->salary=0;//初始
        return p->salary;//返回引用
    }
    void display()
    {
        for(int i=0;i<n;i++)
        cout<<employ[i].name<<"  "<<employ[i].salary<<"   "<<i<<endl;
    }
};

int main()
{
    SalaryManage s(3);
    s["张三"]=2188.88;//n=0
    s["里斯"]=1230.07;//n=1
    s["王五"]=3200.89;//n=2
    s["小花"]=3300.01;//n=3
    cout<<"张三\t"<<s["张三"]<<endl;
    cout<<"里斯\t"<<s["里斯"]<<endl;
    cout<<"王五\t"<<s["王五"]<<endl;
    cout<<"......下为display的输出.....\n"<<endl;
    s.display();
    return 0;
}


