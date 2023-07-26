#include <iostream>
using namespace std;

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600}; // 分配块大小
    int processSize[] = {212, 417, 112, 426}; // 进程大小
    int m = sizeof(blockSize) / sizeof(blockSize[0]); // 分配块数量
    int n = sizeof(processSize) / sizeof(processSize[0]); // 进程数量

    cout<<"进程块的大小:"<<endl;
    for(int i=0;i<m;i++)
        cout<<blockSize[i]<<"\t";
    cout<<endl;
    cout<<"进程大小:"<<endl;
    for(int i=0;i<n;i++)
        cout<<processSize[i]<<"\t";
    cout<<endl;
}