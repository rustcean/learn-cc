/**
 * zoj 1086
*/


#include <iostream>
#include <string.h>
using namespace std;

//计算结果
unsigned char Dec[48];

unsigned char A[48][56];

void Init()
{
    int i,j,carry=0;
    A[0][0]=5;
    for(i=1;i<48;i++)
    {
        for(j=0;j<(i+1);j++)
        {
            A[i][j]=(A[i-1][j]+carry)/2;
            carry=(A[i-1][j] & 1)*10; //不懂
        }
    }
}

//返回digit数位产度

int Convert(char * pOctNum)
{
    //位索引
    int testNum[]={4,2,1};
    int index=0,length=0;
    int i,j,carry,digit;
    char * p=pOctNum+2;

    memset(Dec,0,sizeof(Dec));
    while(*p)
    {
        digit=*p-'0';
        for(j=0;j<3;j++)
        {
            if(digit&testNum[j])
            {
                length=index*3+j+1;
                for(i=0;i<length;i++)
                    Dec[i]+=A[index*3+j][i];
            }
        }
        ++p;
        ++index;
    }

    //归整数位
    for(i=length;i>0;--i)
    {
        if(Dec[i]>9)
        {
            carry=Dec[i]/10;
            Dec[i-1]+=carry;
            Dec[i]=Dec[i]=carry*10;
        }
    }
    return length;
}

int main()
{
    int length,i;
    char line[26];
    Init();
    while((cin>>line)&&line[0]!=0)//更改
    {
        length=Convert(line);
        printf("%s [8] = 0.",line);
        for(i=0;i<length;i++)
        {
            printf("%d",Dec[i]);
        }
        printf("[10]\n");
    }
    return 0;
}

