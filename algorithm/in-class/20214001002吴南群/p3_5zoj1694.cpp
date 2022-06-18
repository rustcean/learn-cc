#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;
int target;
string num;
int mat[10][10];//部分和
int Max,flag[10],reject;
int f[10];//记录剪切点

void DFS( int x,int count )
{
    flag[x] = 1;
    int i;
    if(  x == num.length() )
    {

        if( count == Max && count <= target )
            reject ++;
        if( count > Max && count <= target )
        {
            Max = count;
            reject = 1;
            memcpy(f,flag,sizeof(flag));//将flag拷贝到f上
        }
        flag[x] = 0;
        return;
    }
    for( i = x; i < num.length(); i++ )
        DFS( i+1, count + mat[x][i]);
    flag[x] = 0;
}

int main(void)
{
    int i,j,k,sum;
    while( cin >> target >> num )
    {
        if( !target && num == "0" ) break;

        Max = -1;reject = 0;//初始化
        
        for( i = 0; i < num.length(); i++ )
            for( j = i; j < num.length(); j++ )
            {
                sum = 0;
                for( k = i; k <= j; k++ )
                    sum = sum * 10 + num[k]-'0';
                mat[i][j] = sum;
            }//算出部分和

        memset(flag,0,sizeof(flag));//
        DFS( 0,0 );
        if( reject == 0 )//三种情况
            cout << "error" << endl;
        else if( reject > 1 )
            cout << "rejected" << endl;
        else
        {
            cout << Max ;
            for( i = 0; i < num.length(); i++ )
            {
                if( f[i] ) cout << ' ';//每一个切割点都要输出一个空格
                cout << num[i];
            }
            cout << endl;
        }
    }
    return 0;
}

//与strcpy相比，memcpy并不是遇到'\0'就结束，而是一定会拷贝完n个字节 用来做内存拷贝