#include <iostream>
#include <cstring>
using namespace std;
// 首次适应算法函数
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // 存储分配块的编号
    // 初始化分配块编号为-1
    memset(allocation, -1, sizeof(allocation));
    // 遍历所有进程
    for (int i = 0; i < n; i++) {
        // 遍历所有分配块
        for (int j = 0; j < m; j++) {
            // 如果当前分配块的大小大于等于当前进程的大小，并且该分配块未被分配
            if (blockSize[j] >= processSize[i] && allocation[i] == -1) {
                // 将该进程分配到该分配块中
                allocation[i] = j;
                // 减少该分配块的大小
                blockSize[j] -= processSize[i];
            }
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
    firstFit(blockSize, m, processSize, n);
    return 0;
}