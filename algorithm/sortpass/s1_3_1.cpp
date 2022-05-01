//for(auto i : counts)--遍历完每一个元素
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,0};
    
    vector<int>counts(a,a+6);
    for(auto cont:counts)
        cout<<cont<<" ";
    cout<<endl;
    return 0;
}

