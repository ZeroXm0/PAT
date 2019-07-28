#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 500010;
const int maxs = 51;
set<int> st[maxs];
void compare(int c, int t) {	//放出来，不然会超限，太多循环嵌套 
	int Nc = 0;
	int Nt = st[t].size();
	for(set<int>::iterator it = st[c].begin(); it != st[c].end(); it++) {
		if(st[t].find(*it) != st[t].end()) Nc++;
		else Nt++;
	}
	printf("%.1f%%\n", Nc * 100.0 / Nt);
}
int main() {
	int n, m, k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			scanf("%d", &a);
			st[i].insert(a);
		}
	}
	scanf("%d", &k);
	int c,t;
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &c, &t);
		compare(c, t);
	}
	return 0;
}
