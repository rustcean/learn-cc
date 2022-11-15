#include "p1_2form.h"
#include <iostream>
using namespace std;
//构造函数
template <class T>
SparseMatrix<T>::SparseMatrix(int maxSz):maxTerms(maxSz)
{
    elem=new Trituple<T> [maxSz];
    if(elem==NULL)
        {cerr<<"存储分配出错!"<<endl;exit(1);}
    Rows=Cols=Terms=0;        //第一个元素初始化为0
}
//重载运算符<<
template <class T>
ostream &operator<<(ostream &out, SparseMatrix<T> &M)
{
    out<<"rows= "<<M.Rows<<endl;
    out<<"cols= "<<M.Cols<<endl;
    out<<"Nonzero terms= "<<M.Terms<<endl;
    for(int i=0;i<M.Terms;i++)
        out<<"M["<<M.elem[i].row<<"]["<<M.elem[i].col
            <<"]= "<<M.elem[i].value<<endl;
    return out;
}
// //重载>>
// iostream &operator>>(istream &in, SparseMatrix<T> &M)
// {
//     cout<<"请输入矩阵的行数,列数(例:xx  xx): "<<endl;
//     in>>M.Rows>>M.Cols;
//     Trituple<T> x;
//     int endTag=-1;
//     M.Terms =0;
//     cout<<"请输入元素行号，列号和值(例:xx xx xx): "<<endl;
//     in>>x.row>>x.col>>x.value;
//     while(x.row!=endTag)
//     {
//         M.Insert()
//     }
}

//转置函数
template <class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T> &b)
{
    //将稀疏矩阵a转置，赋给稀疏矩阵b并返回,快速转置运算
    int *rowSize=new int[Cols];
    int *rowStart=new int[Cols];

    b.Rows=Cols;b.Cols=Rows;b.Terms=Terms;
    if(Terms>0)
    {
        int i,j;
        for(i=0;i<Cols;i++) rowSize[i]=0;           //将每列个数初始化为0
        for(i=0;i<Terms;i++) rowSize[elem[i].col]++;//记录每列的元素个数

        rowStart[0]=0;
        for(i=1;i<Cols;i++)
            rowStart[i]=rowStart[i-1]+rowSize[i-1];  //
        
        for(i=0;i<Terms;i++)                         //开始赋值
        {
            j=rowStart[elem[i].col];
            b.elem[j].row=elem[i].col;
            b.elem[j].col=elem[i].row;
            b.elem[j].value=elem[i].value;
            rowStart[elem[i].col]++;                 //位置进一位
        }
    }
    delete []rowSize;
    delete []rowStart;
}

