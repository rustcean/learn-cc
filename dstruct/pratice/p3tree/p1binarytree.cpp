//返回层数的二叉链表
#include <iostream>
using namespace std;

template <class T>
struct BinTreeNode{
    T data;
    BinTreeNode<T> *leftC,*rightC;
    BinTreeNode():leftC(NULL),rightC(NULL){}
    BinTreeNode(T x, BinTreeNode<T> *l=NULL,BinTreeNode<T> *r=NULL)
    :data(x),leftC(l),rightC(r){} 
};

template <class T>
class BinaryTree{
    private:
    T Refvalue; 
    public :
    BinTreeNode<T> *root;
    BinaryTree():root(NULL){}
    BinaryTree(T value):Refvalue(value),root(NULL){}
    void creatBinaryTree(T pre[],BinTreeNode<T> *&subTree,int &n);//建立链表
    void find(BinTreeNode<T> *&subTree,T data);     //寻找对应位置
};

template <class T>
void BinaryTree<T>::creatBinaryTree(T pre[],BinTreeNode<T> *&subTree,int &n){
    T ch=pre[n++];
    if(ch==';')return;
    if(ch!='#'){
        subTree=new BinTreeNode<T>(ch);
        creatBinaryTree(pre,subTree->leftC,n);
        creatBinaryTree(pre,subTree->rightC,n);
    }
    else subTree=NULL;
}

template <class T>
void BinaryTree<T>::find(BinTreeNode<T> *&subTree,T da){
    int static num=1;
    if(subTree!=NULL){
        if(subTree->data==da) cout<<da<<"的层数为: "<<num<<endl;
        else{
            num++;
            find(subTree->leftC,da);
            find(subTree->rightC,da);
        }
    }
}


/*数据:
abc##de#g##f###
c   在第三层  a->b->c
*/
int main(){
    char *pre="abc##de#g##f###;";
    int n=0;
    BinaryTree<char> tree;
    tree.creatBinaryTree(pre,tree.root,n);
    tree.find(tree.root,'a');
    tree.find(tree.root,'c');
}

