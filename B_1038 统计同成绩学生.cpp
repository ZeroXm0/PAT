#include <cstdio>
#include <cstring>
int maxn = 100010;
int main(){
	int n, k, m;
	int hash[110] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &m);
		hash[m]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &m);
		printf("%d", hash[m]);
		if(i != k - 1) printf(" ");
	}
	return 0;
}
