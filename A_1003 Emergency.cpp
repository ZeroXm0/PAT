#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
bool vis[maxn] = {false};
int d[maxn], num[maxn] = {0}, G[maxn][maxn], team[maxn], disM[maxn] = {0};
int n, m, c1, c2;
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	disM[s] = team[s];
	num[s] = 1;
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
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
				num[v] = num[u];
				disM[v] = disM[u] + team[v];
			} else if(d[u] + G[u][v] == d[v]) {
				num[v] += num[u];
				if(disM[u] + team[v] > disM[v]) disM[v] = disM[u] + team[v];
			}
		}
	}
} 
int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++) {
		scanf("%d", &team[i]);
	}
	fill(G[0], G[0] + maxn * maxn, INF);		//记得必须初始化图 
	for(int i = 0; i < m; i++) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		G[u][v] = G[v][u] = l;			//注意为无向图 
	}
	Dijkstra(c1);
	printf("%d %d\n", num[c2], disM[c2]);
	return 0;
}
