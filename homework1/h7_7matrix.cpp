#include <iostream>
#include <cmath>
using namespace std;
class Fan
{
    int n;//维数dimension
    int fan[10][10];//方阵尽量大一些
    public:
    Fan operator+(Fan &f);//
    Fan operator-(Fan &f);//
    Fan operator*(Fan &f);//
    Fan operator=(const Fan &f);
    friend ostream& operator<<(ostream&out,Fan&f);//
    friend istream& operator>>(istream&in,Fan&f);//
    //void setmatrix();
};
Fan Fan::operator+(Fan &f)
{
    Fan result;
    result.n=f.n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    result.fan[i][j]=fan[i][j]+f.fan[i][j];
    return result;
}

Fan Fan::operator-(Fan &f)
{
    Fan result;
    result.n=f.n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    result.fan[i][j]=fan[i][j]-f.fan[i][j];
    return result;
}
Fan Fan::operator*(Fan&f)
{
    Fan result;
    result.n=f.n;
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)   
      for(int k=0;k<n;k++)
       result.fan[i][j]=fan[i][k]*f.fan[k][j];
       return result;
}

Fan Fan::operator=(const Fan &f)
{
    n=f.n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    this->fan[i][j]=f.fan[i][j];
    return *this;
}

ostream & operator<<(ostream&out,Fan&f)
{
    for(int i=0;i<f.n;i++)
    {
        for(int j=0;j<f.n;j++)
        {
            cout<<f.fan[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}
istream& operator>>(istream&in,Fan&f)
{
    cout<<"input dimension of the matrix,but do not over 10 :";
    in>>f.n;
    cout<<"input all the data:"<<endl;
    for(int i=0;i<f.n;i++)
      for(int j=0;j<f.n;j++)
        in>>f.fan[i][j];
    return in;
}


int main()
{
    Fan m1;
    Fan m2;
    cin>>m1;
    cout<<m1;
    cin>>m2;
    cout<<m2;
    cout<<endl;
    Fan m=m1-m2;
    cout<<m;
    cout<<endl;
    m=m1+m2;
    cout<<m;
    m=m1*m2;
    cout<<endl<<m;
    return 0;
}
