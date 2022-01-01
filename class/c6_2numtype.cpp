#include <iostream>
using namespace std;
template <class numtype>
class Compare
{
    public:
    Compare(numtype a,numtype b){x=a;y=b;}
    numtype max()
    {return (x>y)?x:y;}
    numtype min();
    private:
    numtype x,y;

};
template <class numtype>
//在外面声明需要再写一次类型,同时命名函数的格式也要变
numtype Compare <numtype>::min()
{return (x<y)?x:y;}

int main()
{
    Compare <int>c1(1,6);
    cout<<"max: "<<c1.max()<<endl;
    cout<<"min: "<<c1.min()<<endl;
    Compare <float> c2(12.0,20.0);
    cout<<"max: "<<c2.max()<<endl;
    cout<<"min: "<<c2.min()<<endl;
    Compare <char> c3('a','A');
    cout<<"max: "<<c3.max()<<endl;
    cout<<"min: "<<c3.min()<<endl;
    Compare <string> c4("abcd","defgh");
    //虽然有sting类的数据,但是不需要它的函数,所以不需要它的库
    cout<<"max: "<<c4.max()<<endl;
    cout<<"min: "<<c4.min()<<endl;
    return 0;
}