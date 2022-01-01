#include <iostream>//cout重载
using namespace std;
class Mark
{
    int zi;
    int mu;
    public:
    Mark(int z=0,int m=0):zi(z),mu(m){}
    Mark operator<(Mark*m);
    friend ostream & operator<< (ostream &o, Mark &re)
    {
        o<<re.zi<<"/"<<re.mu<<endl;
        return o;
    }
};
// Mark Mark::operator<(Mark&m)
// {
// }


int main()
{
    Mark x(-1,4);
    double s=(double)1/2;//0.25
    cout<<s<<endl;
    double a=1;
    double b=4;
    double c=a/b;//0.25
    cout<<c<<endl;
    if(c<s)cout<<"yes"<<endl;
    return 0;
}
