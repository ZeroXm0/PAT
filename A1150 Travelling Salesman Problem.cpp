#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
using namespace std; 
const int maxn = 210;
const int Inf = 0x3fffffff;
int n, m, k, Min = Inf, idx = -1;
int G[maxn][maxn];
void check(int x) {
	int sum = 0, flag = 1;
	int cnt;
	scanf("%d", &cnt);
	set<int> route;
	vector<int> v(cnt);
	for(int i = 0; i < cnt; i++) {
		scanf("%d", &v[i]);
		route.insert(v[i]);
	}
	for(int i = 0; i < cnt - 1; i++) {
		if(G[v[i]][v[i + 1]] != Inf) sum += G[v[i]][v[i + 1]];
		else flag = 0;
	}
	if(flag == 0) {
		printf("Path %d: NA (Not a TS cycle)\n", x);
	} else if (v[0] != v[cnt - 1] || route.size() != n) {
		printf("Path %d: %d (Not a TS cycle)\n", x, sum);
	} else {
		if(sum < Min) {
			Min = sum;
			idx = x;
		}
		if(cnt == n + 1) {
			printf("Path %d: %d (TS simple cycle)\n", x, sum);
		} else {
			printf("Path %d: %d (TS cycle)\n", x, sum);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	fill(G[0], G[0] + maxn * maxn, Inf);
	G[0][0] = 0;
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &G[a][b]);
		G[b][a] = G[a][b];
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; i++) check(i);
	printf("Shortest Dist(%d) = %d\n", idx, Min);
	return 0;
}
