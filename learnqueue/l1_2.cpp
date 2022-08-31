#include <iostream>
#include <queue>
using namespace std;

struct queuenode
{
    int child;
    int level;
};

int generate(int root)
{
    queue <queuenode>qu; 
    queuenode temp,newtemp;
    int child_num,child,i,maxlevel=0;

    temp.child=root;
    temp.level=1;

    while(!qu.empty())
    {
        temp=qu.front();
        qu.pop();
        if(temp.level>maxlevel)
            maxlevel=temp.level;
        cin>>child_num;
        for(i=0;i<child_num;i++)
        {
            cin>>child;
            newtemp.child=child;
            newtemp.level=temp.level+1;
            qu.push(newtemp);
        }
    }
    return maxlevel;
}

int main()
{
    return 0;
}
