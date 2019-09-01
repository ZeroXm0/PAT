#include <cstdio>
#include <cmath>
#include <cstring>
const int maxn = 510;
bool G[maxn][maxn], vis[maxn];
int deep[maxn];
int n, m, max = 0;
void DFS(int nowVisit, int &numMember) {
	numMember++;
	vis[nowVisit] = true;
	for(int i = 1; i <= n; i++) {
		if(G[nowVisit][i]) {
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if(vis[i] == false) {
				DFS(i, numMember);
			} 
		} 
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		deep[v1]++;
		deep[v2]++;
		G[v1][v2] = G[v2][v1] = true;
	}
	int even = 0;
	for(int i = 1; i <= n; i++) {
		printf("%d", deep[i]);
		if(i != n) printf(" ");
		else printf("\n");
		if(deep[i] % 2 == 0) even++;
	}
	int cnt = 0;
	DFS(1, cnt);
	if(cnt != n || (even != n && even != n - 2)) {
		printf("Non-Eulerian\n");
	} else if(even == n) {
		printf("Eulerian\n");
	} else {
		printf("Semi-Eulerian\n");
	}
	return 0;
} 
