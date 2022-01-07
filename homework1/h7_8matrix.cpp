#include <iostream>
using namespace std;

class Matrix
{
private:
int **p;
int n;
public:
Matrix(int _n)
{
n=_n;
p=new int*[n];
for(int i=0;i<n;i++)
{
p[i]=new int[n];
}

for(i=0;i<n;i++)
for(int j=0;j<n;j++)
{
p[i][j]=j;
}

}

void display()
{
for(int i=0;i<n;i++)
{ for(int j=0;j<n;j++)
{
cout<<p[i][j]<<" ";
}
cout<<endl;
}
}


~Matrix()
{
for(int i=0;i<n;i++)
{
delete []p[i];
}

delete []p;
}

Matrix(const Matrix &m)
{
cout<<"调用copy构造函数"<<endl;
n=m.n;
p=new int*[n];
for(int i=0;i<n;i++)
{
p[i]=new int[n];
}

for(i=0;i<n;i++)
for(int j=0;j<n;j++)
{
p[i][j]=m.p[i][j];
}

}

Matrix& operator=(const Matrix &m)
{

cout<<"调用=运算符"<<endl;

for(int i=0;i<n;i++)
{
delete []p[i];
}
delete []p;

n=m.n;
p=new int*[n];
for(i=0;i<n;i++)
{
p[i]=new int[n];
}


for(i=0;i<n;i++)
for(int j=0;j<n;j++)
{
p[i][j]=m.p[i][j];
}

return *this;
}

};


void main()
{
Matrix a(5);
a.display();

Matrix c(a);
c.display();

Matrix b(6);
b.display();

a=b;
a.display();

}