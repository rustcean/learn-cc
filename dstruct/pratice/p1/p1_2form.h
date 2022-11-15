#ifndef FORM_H
#define FORM_H

//稀疏矩阵的三元组表类定义
#define dafaultsize 100
template <class T>
struct  Trituple
{
    int row,col;   //行号，列号
    T value;       //对应数据
    Trituple <T> & operator =(Trituple<T> &x)
    {
        row=x.row;col=x.col;
        value=x.value;
        return *this;
    }
};

template <class T>
class SparseMatrix
{
    public:
    SparseMatrix(int maxSz=dafaultsize);
    ~SparseMatrix(){delete []elem;}
    SparseMatrix<T> & operator=(SparseMatrix <T> &x);
    void Transpose(SparseMatrix <T> &b);
    //对当前稀疏矩阵对象执行转置
    void Add(SparseMatrix <T> &b, SparseMatrix <T> &c);
    

    private:
    int Rows,Cols,Terms;     //矩阵行数,列数,非零元素个数
    Trituple <T> *elem;      //三元组表
    int maxTerms;            //表的大小
    //运算符重载-友元函数
    friend ostream & operator<<(ostream &out, SparseMatrix <T> &M);
    friend istream & operator>>(istream &in, SparseMatrix<T> &M);
};

#endif