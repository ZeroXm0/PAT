#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1020;
const int INF = 0x3fffffff;
int n, m, k, ds, G[maxn][maxn], d[maxn];
double resAvg = INF, resMin = -1;
bool vis[maxn] = {false};
int getId(char str[]) {
	int len = strlen(str), id = 0;
	for(int i = 0; i < len; i++) {
		if(str[i] != 'G') id = id * 10 + str[i] - '0';
	}
	if(str[0] == 'G') return n + id;
	else return id;
}
void Dijkstra(int s) {
	fill(d, d + maxn, INF); 
	memset(vis, false, sizeof(vis));
	d[s] = 0;
	for(int i = 1; i <= n + m; i++) {
		int u = -1, min = INF;
		for(int j = 1; j <= n + m; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1)	return;
		vis[u] = true;
		for(int v = 1; v <= n + m; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(G[u][v] + d[u] < d[v]) {
					d[v] = G[u][v] + d[u];
				}
			}
		}
	}
}
int solution() {
	int ans = -1;
	for(int i = n + 1; i <= n + m; i++) {
		Dijkstra(i);
		double avg = 0, min = INF;
		bool flag = true;
		for(int j = 1; j <= n; j++) {
			if(d[j] > ds) {
				flag = false;
				break;
			}
			avg += 1.0 * d[j] / n;
			if(d[j] < min) min = d[j];
		}
		if(flag == false) continue;
		if(min > resMin) {			//note:the residential housing is as far away as possible
			ans = i;
			resMin = min;
			resAvg = avg; 
		} else if(min == resMin && avg < resAvg) {
			ans = i;
			resAvg = avg;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	fill(G[0], G[0] + maxn * maxn, INF);
	char str1[5], str2[5];
	int dis;
	while(k--) {
		scanf("%s %s %d", str1, str2, &dis);
		int id1 = getId(str1);
		int id2 = getId(str2);
		G[id1][id2] = G[id2][id1] = dis;
	}
	int i = solution();
	if(i == -1) printf("No Solution\n");
	else {
		printf("G%d\n", i - n);
		printf("%.1f %.1f\n", resMin, resAvg);
	}
	return 0;
}
