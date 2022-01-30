#include <iostream>
using namespace std;

int f(int n, int k);
int main()
{
  cout<<"input x: ";
  int x;
  cin>>x;
  cout<<"input k:";
  int k;
  cin>>k;
  cout<<f(x,k)<<endl;
  return 0;
}
int f(int n,int k)
{
  if((n==k)||(k==0))
    return 1;
  else 
    return f(n-1,k-1)+f(n-1,k);
}
