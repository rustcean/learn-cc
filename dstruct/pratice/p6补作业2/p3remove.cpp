//去除重复的数字--直接覆盖
#include <iostream>
#include <vector>
using namespace std;


int removeDuplicates(vector<int> &nums) {
    int len = nums.size();
    //先判断数组长度
    if (len == 0) {
        return 0;
    }
    //标记
    int slow = 1;
    int fast = 1;
    //删除
    while (fast < len) {
        if(nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }

    return slow;
}

int main()
{
    return 0;
}