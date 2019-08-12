#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1010;
bool vis[maxn] = {false};
vector<int> G[maxn];
int n, m, k, cut;
void DFS(int x) {
	if(x == cut) return;
	vis[x] = true;
	for(int i = 0; i < G[x].size(); i++) {
		if(vis[G[x][i]] == false){
			DFS(G[x][i]);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &cut);
		memset(vis, false, sizeof(vis));
		int block = 0;
		for(int j = 1; j <= n; j++) {
			if(j == cut) continue;
			if(vis[j] == false) {
				DFS(j);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}
