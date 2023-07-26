#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1005; // 二分图中左右两边的最大节点数
vector<int> G[MAXN]; // 二分图的邻接表表示
int match[MAXN]; // 记录右边节点的匹配情况，match[i]表示右边第i个节点被哪个左边节点匹配了
bool vis[MAXN]; // 记录左边节点是否被访问过
bool dfs(int u) { // 从左边第u个节点出发，寻找增广路
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v]) { // 如果右边节点还没有被访问过
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) { // 如果右边节点还没有匹配或者可以和它匹配的左边节点可以找到增广路
                match[v] = u; // 将右边节点与左边第u个节点匹配
                cout<<u<<"--"<<v<<endl;
                return true; // 找到了增广路
            }
        }
    }
    return false; // 找不到增广路
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(match, -1, sizeof(match));
    // int u, v;
    // for (int i = 0; i < k; i++) {
    //     cin >> u >> v;
    //     G[u].push_back(v);
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++) { // 枚举每一个左边的节点
        memset(vis, false, sizeof(vis));
        if (dfs(i)) { // 如果能找到增广路
            ans++; // 增加匹配数
        }
    }
    cout << ans << endl;
    return 0;
}