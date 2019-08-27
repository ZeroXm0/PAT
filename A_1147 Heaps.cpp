#include <cstdio>
const int maxn = 1010;
int m, n, tree[maxn];
int flag;
void check(int i) {
	if(i > n) return;
	int l = 2 * i, r = l + 1;
	for(int j = l; j <= r && j <= n; j++) {
		if(flag == 1 && tree[i] < tree[j]) {
			flag = 0;
			printf("Not Heap\n");
			return;
		}
		if(flag == -1 && tree[i] > tree[j]) {
			flag = 0;
			printf("Not Heap\n");
			return;
		}	
	}
	if(flag != 0) {
		check(l);
		check(r);
	}
}
void DFS(int root) {
	if(root > n) return;
	DFS(root * 2);
	DFS(root * 2 + 1);
	printf("%d", tree[root]); 
	if(root != 1) printf(" ");
	else printf("\n");
}
int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &tree[j]);
		}
		flag = tree[1] >= tree[2] ? 1 : -1;
		check(1);
		if(flag == 1) printf("Max Heap\n");
		else if(flag == -1) printf("Min Heap\n");
		DFS(1);
	}
	return 0;
}
