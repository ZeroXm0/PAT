#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn = 10010;
int father[maxn];
int find(int x) {
	int z = x;
	while(x != father[x]) {
		x = father[x];
	}
	while(z != father[z]) {			//测试点4不通过超时，所以压缩路径，减少复杂度 
		int a = z;
		z = father[z];
		father[a] = x;
	}
	return x;
} 
void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa != fb) {
		father[fa] = fb;
	}
}
set<int> num; 
int main() {
	int n, q;
	scanf("%d", &n);
	for(int i = 0; i < maxn; i++) father[i] = i;
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		vector<int> v(k);
		scanf("%d", &v[0]);
		num.insert(v[0]);
		for(int j = 1; j < k; j++) {
			scanf("%d", &v[j]);
			Union(v[0], v[j]);
			num.insert(v[j]);
		} 
	}
	set<int> tree;
	for(set<int>::iterator it = num.begin(); it != num.end(); it++) {
		int fa = find(*it);
		tree.insert(fa);
	}
	printf("%d %d\n", tree.size(), num.size());
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(find(a) == find(b)) {
			printf("Yes\n");
		}else printf("No\n");
	}
	return 0;
}
