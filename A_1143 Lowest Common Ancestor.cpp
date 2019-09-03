#include <cstdio>
#include <map>
#include <vector> 
using namespace std;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	map<int, bool> vis;
	vector<int> pre(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		vis[pre[i]] = true;
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(vis[a] && vis[b]) {
			int res;
			for(int j = 0; j < n; j++) {
				res = pre[j];
				if((res >= a && res <= b) || (res >= b && res <= a)) {			//由于是前序，所以最小共同跟必最早找到 ,双等于才能找到a是b的父元素的情况 
					break;
				}
			}
			if(res == a || res == b) {
				printf("%d is an ancestor of %d.\n", res == a ? a : b, res == a ? b : a);
			} else {
				printf("LCA of %d and %d is %d.\n", a, b, res);
			}
		} else {
			if(vis[a] == false && vis[b] == false) {
				printf("ERROR: %d and %d are not found.\n", a, b);
			} else {
				printf("ERROR: %d is not found.\n", vis[a] ? b : a);
			}
		}
	}
}
