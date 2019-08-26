#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 510;
const int Inf = 0x3fffffff;
int n, m;
bool vis[maxn];
int G[maxn][maxn], d[maxn], w[maxn], weight[maxn][maxn], pre[maxn], preW[maxn], note[maxn];
vector<int> temp, dis, fast;
void DFS(int k) {
	fill(d, d + maxn, Inf);
	fill(w, w + maxn, Inf);
	fill(vis, vis + maxn, false);
	for(int i = 0; i < n; i++) pre[i] = i;
	d[k] = 0;
	w[k] = 0;
	for(int i = 0; i < n; i++) {
		int idx = -1, min = Inf;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				min = d[j];
				idx = j;
			}
		}
		if(idx == -1) return;
		vis[idx] = true;
		for(int v = 0; v < n; v++) {
			if(G[idx][v] != Inf && vis[v] == false) {
				if(G[idx][v] + d[idx] < d[v]) {
					d[v] = G[idx][v] + d[idx];
					w[v] = weight[idx][v] + w[idx];
					pre[v] = idx;
				} else if(weight[idx][v] + w[idx] < w[v] && d[v] == G[idx][v] + d[idx]) {
					w[v] = weight[idx][v] + w[idx];
					pre[v] = idx;
				}
			}
		}
	}
}
void DFSW(int k) {
	fill(d, d + maxn, Inf);
	fill(w, w + maxn, Inf);
	fill(vis, vis + maxn, false);
	d[k] = 0;
	w[k] = 0;
	for(int i = 0; i < n; i++) {
		int idx = -1, min = Inf;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && w[j] < min) {
				min = w[j];
				idx = j;
			}
		}
		if(idx == -1) return;
		vis[idx] = true;
		for(int v = 0; v < n; v++) {
			if(weight[idx][v] != Inf && vis[v] == false) {
				if(weight[idx][v] + w[idx] < w[v]) {
					note[v] = note[idx] + 1;			//用note记录前面的点的个数 
					w[v] = weight[idx][v] + w[idx];;
					preW[v] = idx;
				} else if(1 + note[idx] < note[v] && w[v] == weight[idx][v] + w[idx]) {
					note[v] = note[idx] + 1;
					preW[v] = idx;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	fill(G[0], G[0] + maxn * maxn, Inf);
	fill(weight[0], weight[0] + maxn * maxn, Inf);
	for(int i = 0; i < m; i++) {
		int v1, v2, way, length, time;
		scanf("%d%d%d%d%d", &v1, &v2, &way, &length, &time);
		G[v1][v2] = length;
		weight[v1][v2] = time;
		if(way == 0) {
			G[v2][v1] = length;
			weight[v2][v1] = time;
		}
	}
	int sour, dest;
	scanf("%d%d", &sour, &dest);
	DFS(sour);
	int distance = d[dest];
	int end = dest;
	while(end != sour) {
		dis.push_back(end);
		end = pre[end];
	}
	dis.push_back(sour);
	DFSW(sour);
	int T = w[dest];
	end = dest;
	while(end != sour) {
		fast.push_back(end);
		end = preW[end];
	}
	fast.push_back(sour);
	if(dis == fast) {
		printf("Distance = %d; Time = %d: ", distance, T);
		for(int i = dis.size() - 1; i >= 0; i--) {
			printf("%d", dis[i]);
			if(i != 0) printf(" -> ");
			else printf("\n");
		}
	} else {
		printf("Distance = %d: ", distance);
		for(int i = dis.size() - 1; i >= 0; i--) {
			printf("%d", dis[i]);
			if(i != 0) printf(" -> ");
			else printf("\n");
		}
		printf("Time = %d: ", T);
		for(int i = fast.size() - 1; i >= 0; i--) {
			printf("%d", fast[i]);
			if(i != 0) printf(" -> ");
			else printf("\n");
		}
	}
	return 0;
}
