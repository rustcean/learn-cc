#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,m;
    char s[1001],a[101][1001];
    scanf("%d",&n);
    cin.get();
    cin.getline(s,1001);
    int l=strlen(s),t=0;//
    m=(l+n-1)/n;/*m=l/n; if(l%n!=0) m++;*/
    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
            if(t<l) 
               a[i][j]=s[t++];
            else
              a[i][j]=' ';//不足补空
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
           printf("%c",a[j][i]);
        printf("\n");
    }
}