#include "bsTree.h"
using namespace std;
int main()
{
    const int number=10;
    int v[number]={2,3,5,1,4,6,8,9,0,7};
    string d[number]={"li","hua","xiao","ming","hong","gang","jie","son","jin","jing"};
    Node arr[number];
    for(int i=0;i<number;i++)
    {
        arr[i].key=v[i];
        arr[i].data=d[i];
    }
    bsTree t;
    t.createbsTree(arr,number);
    Node *pr;
    Node *p=t.Search(arr[3],pr);
    cout<<"查找某一个元素 arr[3]=  \t";
    cout<<p->data<<" "<<p->key<<endl;

    cout<<endl<<"插入一个元素 Node(14,'lijinjin'): "<<endl;
    Node no(14,"lijinjin");
    t.Insert(no);
    cout<<"查看是否在树中: "<<endl;
    p=t.Search(no,pr);
    if(!p)cout<<"不在"<<endl;
    else cout<<"在,数据为: "<<p->key<<" "<<p->data<<endl;

    cout<<endl<<"删除一个节点 Node(14,'lijinjin'):"<<endl;
    t.remove(no);
    cout<<"重新查找该节点:"<<endl;
    p=t.Search(no,pr);
    if(!p)cout<<"不在"<<endl;
    else cout<<"在,数据为: "<<p->key<<" "<<p->data<<endl;

    cout<<endl<<"判断该树是否为搜索树:"<<endl;
    if(!t.IsbsTree(t.root))
        cout<<"不是搜索树"<<endl;
    else cout<<"是搜索树"<<endl;
    
    return 0;
}




