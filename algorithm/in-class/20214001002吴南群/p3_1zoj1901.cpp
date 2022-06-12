#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<iterator>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define eps 1e-6
   
using namespace std;
typedef unsigned long long LL;  
typedef pair<LL, int> P;
const int maxn = 220;
const int mod = 2000000007;
int x[maxn], y[maxn];
double solve(int n, double a, double b);
double getans(int n, double a, double b);

int main()
{
    int n, i, j, k;
    double ans = 1e10;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d", &x[i], &y[i]);
    for(i=0;i<10;i++)
        ans = min(solve(n, rand()%10000, rand()%10000), ans);
    printf("%.0f", ans);
    return 0;
}
double solve(int n, double a, double b)
{
    double ans = getans(n, a, b);
    for(double i=200000;i>eps;i*=0.8){
        double nx = a, ny = b, as = ans;
        if(getans(n, a+i, b)<as){
            as = getans(n, a+i, b);
            nx = a+i, ny = b;
        }
        if(getans(n, a-i, b)<as){
            as = getans(n, a-i, b);
            nx = a-i, ny = b;
        }
        if(getans(n, a, b+i)<as){
            as = getans(n, a, b+i);
            nx = a, ny = b+i;
        }
        if(getans(n, a, b-i)<as){
            as = getans(n, a, b-i);
            nx = a, ny = b-i;
        }
        a = nx, b = ny, ans = as;
    }
    return ans;
}

double getans(int n, double a, double b)
{
    double ans = 0;
    for(int i=0;i<n;i++)
        ans += sqrt((x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b));
    return ans;
}