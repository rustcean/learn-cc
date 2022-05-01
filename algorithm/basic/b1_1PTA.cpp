//PTA-L1-046--整除光棍
// #include <iostream>
// using namespace std;
// int main() {
//     int n, ans = 1, cnt = 1;
//     cin >> n;
//     while (ans < n) {
//         ans = ans * 10 + 1;
//         cnt++;//记录位数
//     }
//     while(1){
//         cout << ans / n;//当成像是数除不尽就向后取位
//         if(ans % n == 0) break;//整除了就退出
//         ans = (ans % n) * 10 + 1;//向后取位1
//         cnt++;//记录位数
//     }
//     cout << ' ' <<  cnt;
//     return 0;
// }
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,num=1,count=1;
    cin>>n;
    while(num<n)
    {
        num=num*10+1;
        count++;
    }
    while(1)
    {
        cout<<num/n;
        if(num%n==0)break;
        num=(num%n)*10+1;
        count++;
    }
    cout<<" "<<count<<endl;
    return 0;
}


