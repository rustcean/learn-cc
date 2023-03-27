/* 最长公共子序列 LCS
* 子序列概念:给定一个序列X=<x1,x2,x3,x4...,xm>，另一个序列Z=<z1,z2,z3,z4...,zk>，
* 若存在一个严格递增的X的下标序列<i1,i2,i3,...,ik>对所有的1,2,3,...,k，
* 都满足x(ik)=zk，则称Z是X的子序列 例:比如Z=<B,C,D,B>是X=<A,B,C,B,D,A,B>的子序列
* 做法: 蛮力枚举不行 -动态规划:
* 
*/


#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
void LCS(string s1,string s2){
    int m=s1.length()+1;
    int n=s2.length()+1;    
    int **p1; //记录数据
    int **p2; //标记
    p1=new int *[m];//指针数组
    p2=new int *[m];//指针数组
    for(int i=0;i<m;i++){
        p1[i]=new int [n];//每个指针指向了一个数组
        p2[i]=new int [n];//
        for(int j=0;j<n;j++)
            p2[i][j]=0;
    }
    //
    for(int i=0;i<m;i++) //把第一行置0
        p1[i][0]=0;
    for(int i=0;i<n;i++)//把第一列置0
        p1[0][1]=0; 
    //
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            if(s1[i]==s2[j]){
                p1[i+1][j+1]=p1[i][j]+1;
                p2[i+1][j+1]=1; //1表示箭头为左上
            }
            else if(p1[i][j+1]>=p1[i+1][j]){
                p1[i+1][j+1]=p1[i][j+1];
                p2[i+1][j+1]=2; //2表示箭头为 上
            }
            else{
                p1[i+1][j+1]=p1[i+1][j];
                p2[i+1][j+1]=3; //3表示箭头为 左
            }
        }
    }
    for(int i=0;i<m;i++)  //输出p1 数组
    {
        for(int j=0;j<n;j++)
            cout<<p1[i][j]<<" ";
        cout<<endl;
    }

    stack<char> same;   //存LCS字符
    stack<int> same1,same2;//存LCS字符在p1 p2的下标
    for(int i=m-1,j=n-1; i>=0 && j>=0;){
        if(p2[i][j]==1){
            i--;
            j--;
            same.push(s1[i]);
            same1.push(i);
            same2.push(j);
        }
        else if(p2[i][j]==2){
            i--;
        }
        else 
            j--;
    }
    cout<<s1<<endl;  //输出字符串1
    for(int i=0;i<m && !same1.empty();i++) //输出字符串1的标记
    {
        if(i==same1.top()){
            cout<<1;
            same1.pop();
        }
        else
            cout<<" ";
    }
    cout<<endl;
    cout<<s2<<endl;  //输出字符串2
    for(int i=0;i<n && !same2.empty();i++) //输出字符串2的标记
    {
        if(i==same2.top()){
            cout<<1;
            same2.pop();
        }
        else
            cout<<" ";
    }
    cout<<endl;
    cout<<"最长公共子序列: "<<endl;
    while(!same.empty()){
        cout<<same.top();
        same.pop();
    }
    cout<<endl;
    cout<<"长度为: "<<endl;
    cout<<p1[m-1][n-1]<<endl;
    for(int i=0;i<m;i++){
        delete [] p1[i];
        delete [] p2[i];
    }
    delete [] p1;
    delete [] p2;
}

int main(){
    string s1="OSDIHGKODGHBLKSJBHKAGHI";
    string s2="ABCPDSFJGODIHJOFDIUSHGD";
    // string s1;
    // string s2;
    // // cout<<"输入字符串1: ";
    // cin>>s1;
    // // cout<<"输入字符串2: ";
    // cin>>s2;
    LCS(s1,s2);
    return 0;
}

