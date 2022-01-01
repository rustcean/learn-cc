#include <iostream>
using namespace std;
class Student
{
    public:
    Student(int n,int a,float s):num(n),age(a),score(s){}
    void total();
    static float average();//static 一般写在最前面
    private:
    int num;
    int age;
    float score;
    static float sum;
    static int count;
};
void Student::total()
{
    sum+=score;
    //cout<<sum<<endl;
    count++;
}
//通过static sum的性质增加score最终产生total的效果
float Student::average()//命名方式没有变化
{
    //只用静态成员函数引用静态数据成员,不引用非静态数据成员,虽然你实际还是会的
    //cout<<sum<<"  "<<count<<endl;
    return (sum/count);
}
float Student::sum=0;
int Student::count=0;
int main()
{
    Student s[3]={
        Student(1001,18,70),
        Student(1002,19,78),
        Student(1005,20,98)
    };
    int n;
    cout<<"please input the number of students: ";
    cin>>n;
    for(int i=0;i<n;i++)
    s[i].total();
    cout<<Student::average()<<endl;
    return 0;
}