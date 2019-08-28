#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 210;
const int inf = 0x3fffffff;
bool G[maxn][maxn];
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int v1, v2; 
		scanf("%d%d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = true;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		int num, pre;
		scanf("%d %d", &num, &pre);
		int first = pre, last = 0;
		bool flag = true;
		set<int> q;
		for(int j = 1; j < num; j++) {
			int now;
			scanf("%d", &now);
			if(G[pre][now] == false) {
				flag = false;
			} else {
				q.insert(now);
			}
			pre = now;
			if(j == num - 1) last = now;
		}
		if(flag && last == first && q.size() == n && num == n + 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
