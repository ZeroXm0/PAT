#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
int n, m, s, des, d[maxn], G[maxn][maxn], cost[maxn][maxn], minCost[maxn], pre[maxn];
bool vis[maxn] = {false};
vector<int> path;
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	fill(minCost, minCost + maxn, INF);
	d[s] = 0;
	minCost[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(G[u][v] + d[u] < d[v]) {
					d[v] = G[u][v] + d[u];
					minCost[v] = minCost[u] + cost[u][v];
					pre[v] = u;
				} else if(G[u][v] + d[u] == d[v] && minCost[v] > minCost[u] + cost[u][v]) {
					pre[v] = u;
					minCost[v] = minCost[u] + cost[u][v];
				}
			}
		}
	}
} 
void DFS(int v) {
	if(v == s) {
		printf("%d ", v);
		return;
	}
	DFS(pre[v]);
	printf("%d ", v);
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &des);
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(cost[0], cost[0] + maxn * maxn, INF);
	for(int i = 0; i < m; i++) {
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		scanf("%d%d", &G[c1][c2], &cost[c1][c2]);
		G[c2][c1] = G[c1][c2];
		cost[c2][c1] = cost[c1][c2];
	}
	Dijkstra(s);
	DFS(des); 
	/* 
	printf("%d ", s); 
	int k = des;			//此处用深度优先算法打印更简洁 
	while(k != s) {
		path.push_back(k);
		k = pre[k];
	}
	for(int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	*/ 
	printf("%d %d\n", d[des], minCost[des]);
	return 0;
}
