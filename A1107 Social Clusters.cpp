#include <cstdio>
#include <algorithm>
using namespace std;
int n, father[1001], isRoot[1001] = {0}, course[1001] = {0};
void init(int n) {
	for(int i = 1; i <= n; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}
int findFather(int k) {
	int a = k;
	while(k != father[k]) {
		k = father[k];
	}
	while(a != father[a]) {			//路径压缩，方便之后查找，减少复杂度，将所有元素转为根节点子元素 
		int z = a;
		a = father[a];
		father[z] = k;
	}
	return k;
}
void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb) {
		father[fa] = fb;
	}
} 
int main() {
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++) {
		int f;
		scanf("%d:", &f);
		for(int j = 1; j <= f; j++) {
			int h;
			scanf("%d", &h);
			if(course[h] == 0) course[h] = i;
			Union(i, findFather(course[h]));
		}
	}
	for(int i = 1; i <= n; i++) {
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(isRoot[i] != 0) ans++;
	}
	printf("%d\n", ans);
	sort(isRoot + 1, isRoot + 1 + n);
	for(int i = n; i > n - ans; i--) {
		printf("%d", isRoot[i]);
		if(i != n - ans + 1) printf(" ");
		else printf("\n");
	}
	return 0;
}
