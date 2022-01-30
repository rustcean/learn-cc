#include <iostream>
using namespace std;
void move(char A,char B);
void hanio(int n,char A,char B,char C);
int main()
{
    cout<<"汉诺塔:"<<endl;
    int disk;
    cout<<"输入层数: ";
    cin>>disk;
    hanio(disk,'A','B','C');
    return 0;
}
void move(char A,char B)
{
    cout<<A<<"->"<<B<<endl;
}
void hanio(int n,char A,char B,char C)
{
    if(n==1)
    move(A,C);
    else
    {
        hanio(n-1,A,C,B);
        move(A,C);
        hanio(n-1,B,A,C);
    }
}
