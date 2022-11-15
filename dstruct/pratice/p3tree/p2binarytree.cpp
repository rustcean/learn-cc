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
    void creatBinaryTree(T pre[],BinTreeNode<T> *&subTree,int &n);
    void change(BinTreeNode<T> *&subTree);
    void show(BinTreeNode<T> *&subTree);
};

template <class T>
void BinaryTree<T>::creatBinaryTree(T pre[],BinTreeNode<T> *&subTree,int &n){
    T ch=pre[n++];
    if(ch==-1)return;
    if(ch!=0){
        subTree=new BinTreeNode<T>(ch);
        creatBinaryTree(pre,subTree->leftC,n);
        creatBinaryTree(pre,subTree->rightC,n);
    }
    else subTree=NULL;
}

template <class T>
void BinaryTree<T>::change(BinTreeNode<T> *&subTree){
    if(subTree!=NULL){
        if( subTree->leftC!=NULL && subTree->rightC!=NULL){
            if(subTree->leftC->data>subTree->rightC->data){
                T tmp=subTree->leftC->data;
                subTree->leftC->data=subTree->rightC->data;
                subTree->rightC->data=tmp;
        }

    }
    change(subTree->leftC);
    change(subTree->rightC);    
    }
}

template <class T>
void BinaryTree<T>::show(BinTreeNode<T> *&subTree){
    if(subTree!=NULL){
        cout<<subTree->data<<" ";
        show(subTree->leftC);
        show(subTree->rightC);  
    }

}
//abc##de#g##f###
int main(){
    int pre[]={9,8,7,0,0,4,3,0,1,0,0,4,0,0,0,-1};
    int n=0;
    BinaryTree<int> tree;
    tree.creatBinaryTree(pre,tree.root,n);
    tree.change(tree.root);
    tree.show(tree.root);
    cout<<endl;
}



