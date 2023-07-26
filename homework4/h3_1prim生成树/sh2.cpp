// 由ai做的
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
/* 定义边结构体 */
struct Edge {
    int from;			//起始点
    int to;				//结束点
    int weight;			//对应权值
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
/* 定义比较器 */
struct cmp {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};
/* 定义 Prim 算法函数 */
vector<Edge> prim(map<int, map<int, int>>& graph, int start) {
    vector<Edge> edges;
    vector<bool> visited(graph.size() + 1, false);		//用来判断有没有在圈内
    priority_queue<Edge, vector<Edge>, cmp> pq;			//优先队列
    //开始
	pq.push(Edge(0, start, 0));
	while (!pq.empty()) {
		//取出队头元素
        Edge e = pq.top();
        pq.pop();
		//如果该元素的终点已经被访问，跳过该元素
        if (visited[e.to]) {
            continue;//结束本次循环
        }
		//将该元素的终点标记为已被访问
        visited[e.to] = true;
		//将该元素加入边集合
        edges.push_back(e);
        //遍历该元素的所有邻居,将未访问的邻居加入优先队列
		for (auto& p : graph[e.to]) {
            int neighbor = p.first;
            int weight = p.second;
            if (!visited[neighbor]) {		//如果没访问过
                pq.push(Edge(e.to, neighbor, weight));
            }
        }
    }
    return edges;
}
/* 主函数 */
int main() {
    // 定义图的邻接表
    map<int, map<int, int>> graph = {
        {1, {{2, 1}, {3, 3}, {4, 4}}},
        {2, {{1, 1}, {3, 2}, {4, 5}}},
        {3, {{1, 3}, {2, 2}, {4, 6}}},
        {4, {{1, 4}, {2, 5}, {3, 6}}}
    };
    // 从 1 号顶点开始生成最小生成树
    auto edges = prim(graph, 1);
    // 输出最小生成树的边集合
    cout<<"输出格式为: from-->to--weight"<<endl;
	for (auto& e : edges) {
        cout << e.from << " " << e.to << " " << e.weight << endl;
    }
    return 0;
}