/*
动态规划:
*/
//1.
#include <iostream>
using namespace std;
//斐波数列--一维数组
int save[100]={-1};
int f(int n)
{
    if(save[n]!=-1)return save[n];
    if(n==0){save[n]=1;return save[n];}
    if(n==1){save[n]=1;return save[n];}
    save[n]=f(n-1)+f(n-2);
    return save[n];
}

int f1(int n)
{
    save[0]=1;save[1]=1;
    for (int i=2;i<n;i++)
        save[i]=save[i-1]+save[i-2];
    return save[n];
}


//组合数
int mat[20][20]={-1};
int Rcom(int m,int n)
{
    if(mat[m][n]!=0)return mat[m][n];
    if(n=0||m==n)
    {
        mat[m][n]=1;return 1;
    }
    mat[m-1][n-1]=Rcom(m-1,n-1);
    mat[m-1][n]=Rcom(m-1,n);
    mat[m][n]=mat[m-1][n-1]+mat[m-1][n];
    return mat[m][n];
}

int Rcom2(int m,int n)
{
    int i,j;
    if(n==0||m==n)return 1;
    for(j=0;j<=n;j++)
    {
        mat[j][j]=1;
        for(i=j+1;i<=m;i++)
        {
            if(j==0)mat[i][j]=1;
            else mat[i][j]=mat[i-1][j]+mat[i-1][j];
        }
    }
    return mat[m][n];
}


#define max 15
int a[max][max];
int opt[max][max]={-1};

int sum(int i,int j,int n)
{
    if(opt[i][j]!=-1)return opt[i][j];
    if(i==n-1){opt[i][j]=a[i][j];return a[i][j];}
    else{
        opt[i+1][j]=sum(i+1,j,n);
        opt[i+1][j+1]=sum(i+1,j+1,n);
        if(opt[i+1][j]>opt[i+1][j+1])
            return opt[i+1][j]+a[i][j];
        else return opt[i+1][j+1]+a[i][j];
    }
}
int main()
{
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
            cin>>a[i][j];
    cout<<sum(0,0,n);
}













