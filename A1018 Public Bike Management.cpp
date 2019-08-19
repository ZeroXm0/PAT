#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 0x3fffffff;
int cmax, n, sp, m, minNeed = inf, minRemain = inf;
bool vis[maxn] = {false};
int G[maxn][maxn], d[maxn], weight[maxn] = {0};		//G[][]记录路径权值， d[]记录最短距离， weight[]记录需要增加的自行车数量
vector<int> pre[maxn];
vector<int> tempPath, path;
void Dijkstra(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	for(int i = 0; i <= n; i++) {
		int u = -1, min = inf;
		for(int j = 0; j <= n; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j; 
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++) {
			if(G[u][v] != inf && vis[v] == false) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
} 
void DFS(int v) {
	tempPath.push_back(v);
	if(v == 0) {
		int need = 0, remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			if(weight[id] > 0)	remain += weight[id];
			else {
				if(remain > abs(weight[id]))	remain -= abs(weight[id]);
				else {
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed) {
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		} else if (need == minNeed && remain < minRemain) {
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();		//退回递归 ，继续寻找其他路径 
		return;
	}
	for(int i = 0; i < pre[v].size(); i++)	DFS(pre[v][i]);
	tempPath.pop_back();
}
int main() {
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	fill(G[0], G[0] + maxn * maxn, inf);
	int u, v, l, num;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num); 
		weight[i] = num - cmax / 2;
	}
	while(m--) {
		scanf("%d%d%d", &u, &v, &l);
		G[u][v] = G[v][u] = l; 
	}
	Dijkstra(0);
	DFS(sp);
	printf("%d ", minNeed);
	for(int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if(i != 0)	printf("->");
	}
	printf(" %d", minRemain);
	return 0;
}
