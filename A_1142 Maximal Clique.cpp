#include <cstdio>
#include <cstring>
const int maxn = 210;
int nv, ne, m, g[maxn][maxn];
bool vis[maxn];
int main() {
	scanf("%d%d", &nv, &ne);
	while(ne--) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	scanf("%d", &m); 
	while(m--) {
		memset(vis, false, sizeof(vis));
		int k, data[maxn];
		scanf("%d", &k);
		int flag = 1; 		//-1:not 0:not max 1:max;
		for(int i = 0; i < k; i++) {
			scanf("%d", &data[i]);
			vis[data[i]] = true;
			for(int j = 0; j < i; j++) {
				if(g[data[i]][data[j]] != 1) {
					flag = -1;
				}
			}
		}
		if(flag == -1) {
			printf("Not a Clique\n");
		} else {
			for(int i = 1; i <= nv; i++) {
				if(vis[i] == false) {
					int j = 0;
					while(j < k && g[data[j]][i]) {
						j++;
					}
					if(j == k) {
						flag = 0;
						break;
					}
				}
			}
			if(flag) {
				printf("Yes\n");
			} else {
				printf("Not Maximal\n");
			}
		}
	}
	return 0;
} 
