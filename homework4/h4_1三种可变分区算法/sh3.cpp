// 最差适应算法

#include <iostream>
#include <cstring>
using namespace std;
// 最差适应算法函数
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // 存储分配块的编号
    // 初始化分配块编号为-1
    memset(allocation, -1, sizeof(allocation));
    // 遍历所有进程
    for (int i = 0; i < n; i++) {
        int worstBlock = -1;
        // 遍历所有分配块
        for (int j = 0; j < m; j++) {
            // 如果当前分配块的大小大于等于当前进程的大小，并且该分配块未被分配
            if (blockSize[j] >= processSize[i] && allocation[i] == -1) {
                // 如果当前分配块是最差分配块，或者当前分配块比之前判断的最差分配块更大，则将该分配块设置为最差分配块
                if (worstBlock == -1 || blockSize[j] > blockSize[worstBlock])
                    worstBlock = j;
            }
        }
        // 如果找到了最差分配块，则将该进程分配到该分配块中
        if (worstBlock != -1) {
            allocation[i] = worstBlock;
            blockSize[worstBlock] -= processSize[i];
        }
    }
    // 输出分配结果
    cout << "进程编号\t进程大小\t分配块编号\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "未分配";
        cout << endl;
    }
}
int main() {
    int blockSize[] = {100, 500, 200, 300, 600}; // 分配块大小
    int processSize[] = {212, 417, 112, 426}; // 进程大小
    int m = sizeof(blockSize) / sizeof(blockSize[0]); // 分配块数量
    int n = sizeof(processSize) / sizeof(processSize[0]); // 进程数量
    cout<<"最差适应算法:"<<endl;
    worstFit(blockSize, m, processSize, n);
    return 0;
}
