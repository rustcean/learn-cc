#include <iostream>
using namespace std;

int main()
{
    return 0;
}
template <class T>
void ThreadTree<T>::PostOrder(ThreadTree<T> *p){
    ThreadTree<T> *t = p;      //指向p
    while(t->ltag == 0 || t->rtag == 0)       //寻找后序下的第一个节点
        if(t->lta == 0) t=t->lefttChird;
        else if(t->rtag == 0) t=t-rightChird; 
    
    cout<<t->data;              //将第一个节点数据输出
    
    while((p=parent(t))!= NULL){              //如果父节点不为空
        if(p->rightChild == t || p->rtag == 1 )  //t是p的后序后继 或者是最后一个节点
            t = p;
        else{                                 //如果不是
            t = p->rightChild;
            while(t->ltag ==0 || t->rtag ==0 )
                if(t->ltag ==0) t=t->leftChild;
                else if(t->rag == 0) t=t->rightChild;
        }
        cout<<t->data;                       //输出
    }     
}


template <class T>
ThreadNode<T> * ThreadTree<T>::parent(ThreadNode<T> *t){
    ThreadNode<T> *p;
    if(t == NULL || t==root ) return NULL;    //如果没有父节点
    for(p=t;p->ltag == 0;p=p->leftChild );

    if(p->leftChild!=NULL){                   //第一条路径
        p=p->leftChild;                       //从左节点开始
        while(p!=NULL && p->leftChild!=t && p->rightChild!=t)  //往前找
            p=p->rightChild;
    }

    if(p==NULL || p->leftChild==NULL){         //第二条路径--如果第一条没找到
        for(p=t;p->rtag==0;p=p->rightChild)    //从右子节点开始移到最后
        p=p->leftChild;                        //从左节点开始
        while(p!=NULL && p->leftChild!=t && p->rightChild!=t) //回到开头，按步寻找
            p=p->rightChild;
    }
}