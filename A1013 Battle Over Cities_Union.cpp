#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1010;
int father[maxn], vis[maxn] = {false};
int n, m, k, cut;
vector<int> G[maxn];
void init() {
	for(int i = 1; i <= n; i++)	{
		father[i] = i;
	}
} 
int findFather(int x) {
	int a = x;
	while(x != father[x]) x = father[x];
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = a;
	}
	return x;
}
void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb) {
		father[fb] = fa;
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
		int city;
		scanf("%d", &city);
		init();
		memset(vis, false, sizeof(vis));
		for(int j = 1; j <= n; j++) {
			for(int s = 0; s < G[j].size(); s++) {
				int u = j, v = G[j][s];
				if(u != city && v != city) {
					Union(u, v);
				}
			}
		}
		int block = 0;
		for(int j = 1; j <= n; j++) {
			if(j == city) continue;
			int fj = findFather(j);
			if(vis[fj] == false) {
				block++;
				vis[fj] = true;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}
