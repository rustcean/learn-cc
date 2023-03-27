// 动态规划--将大问题不断分成小问题 计算
/*一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
  求该青蛙跳上一个 10 级的台阶总共有多少种跳法
*/
/*分析:
    f（10） = f（9）+f(8)
    f (9)  = f(8) + f(7)
    ......
    公式: f(n)=f(n-1)+f(n-2)
    其中，若直接用加法计算 则f(9)被算两次,f(8)被算3次，需要用记忆
        而且每次只要记住f(n-1)和f(n-2)即可

*/
#include <iostream>
#include <map>   //用来记忆
using namespace std;
class Solution{
    public:
    int climStairs(int n)
    {
        int p=0,q=0,r=1;
        for(int i=1;i<=n;i++) //逐步计算
        {
            p=q;   
            q=r;   
            r=p+q;
        }
        return r;
    }
};

int main()
{
    int n;
    cout<<"输入n: ";
    cin>>n;
    Solution s;
    int re=s.climStairs(n);
    cout<<"结果: "<<re<<endl;
    return 0;
}