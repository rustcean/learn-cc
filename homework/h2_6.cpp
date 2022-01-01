#include <iostream>//abs()绝对值函数
#include <cstring>
#include <cmath>
#include<iomanip>

using namespace std;

int get(string *words,int n,string w1,string w2)
{
    int p1[100],p2[100];
    int n1=0,n2=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(words[i]==w1)
        p1[n1++]=i;//记录位置
        else if(words[i]==w2)
        p2[n2++]=i;
    }
    if(n1==0||n2==0)
    return -1;
    int mindis=100000;//先提高初值，才可以找到最短距离
    for(i=0;i<n1;i++)
    for(j=0;j<n2;j++)
    {
        if(abs(p1[i]-p2[j])<mindis)
        mindis=abs(p1[i]-p2[j]);
    }
    return mindis;
}
int main()
{
    string words[1000];
    int n=0;//用来记录句子长度
    while(cin>>words[n++])//读取一开始的句子
    {
        if(cin.get()=='\n')//记录每一个单词
        break;
    }
    string w1,w2;
    cin>>w1>>w2;//读取两个单词，
    cout<<get(words,n,w1,w2)<<endl;
    return 0;
}