#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
//命名
using uchar =unsigned char;

struct Node
{
    uchar c;
    int freq;
    Node *left; //左指针
    Node *right;//右指针
    Node(uchar _c,int f, Node *l=nullptr, Node * r=nullptr)
        :c(_c),freq(f),left(l),right(r){}
    bool operator<(const Node &node)const
    {
        //重载,优先队列的底层数据结构 std::heap 是最大堆
        return freq > node.freq;
    }
};

class huffree
{
    public:
    huffree(const std::map<uchar,int>& afMap)
    {
        for(auto i : afMap)
        {
            Node n(i.first,i.second);
        }
        _makehuffTree();
    }
    ~huffree()
    {
        Node node =q.top();
        _deleteTree(node.left);
        _deleteTree(node.right);
    }
    //
    void huffmanCode(std::map<uchar,std::string> & codeMap)
    {
        Node node=q.top();
        std::string prefix;
        _huffmanCode(&node, prefix,codeMap);
    }
    private:
    static bool _isLeaf(Node *n)
    {
        return n->left==nullptr &&n->right==nullptr;
    }
    //删除哈夫曼
    void _deleteTree(Node *n)
    {
        if(!n)return;//如果为空，返回
        _deleteTree(n->left);//先往后走，后面一步一步往回删
        _deleteTree(n->right);
        delete n;
    }
    void _makehuffTree()
    {
        while(q.size()!=1)
        {
            Node *left =new Node(q.top());q.pop();
            Node *right=new Node(q.top());q.pop();
            Node node('R',left->freq + right->freq,left,right);
            q.push(node);
        }
    }

    void _huffmanCode(Node *root,std::string &prefix,
            std::map<uchar,std::string>& codeMap ){
        std::string tmp=prefix;
        if(root->left !=nullptr)
        {
            prefix+='0';
            if(_isLeaf(root->left))
                codeMap[root->left.c]=prefix;
            else
                _huffmanCode(root->left,prefix,codeMap);
        }
        if(root->right!=nullptr)
        {
            prefix=tmp;
            prefix+='1';
            if(_isLeaf(root->right))
                codeMap[root->right.c]=prefix;
            else
                _huffmanCode(root->right,prefix,codeMap);
        }
    }
    private:
    std::priority_queue<Node> q;
};



int main()
{
    
}




