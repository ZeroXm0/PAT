#include <cstdio>
#include <cstring>
const int maxn = 210;
const int maxl = 10010;
int hashFav[maxn];
int n, m, l, fav[maxn], f[maxl], dp[maxl];      //note:数组长度不同
int main() {
	scanf("%d%d", &n, &m);
    memset(hashFav, -1, sizeof(hashFav));
	for(int i = 0; i < m; i++) {
		scanf("%d", &fav[i]);
		hashFav[fav[i]] = i + 1;
	}
	scanf("%d", &l);
	int num = 0;
	for(int i = 0; i < l; i++) {
		int k;
		scanf("%d", &k);			//只把喜欢的添加入f数组 
		if(hashFav[k] > 0) f[num++] = hashFav[k];
	}
	int ans = -1;
	for(int i = 0; i < num; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(f[i] >= f[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if(dp[i] > ans) ans = dp[i];
	}
	printf("%d\n", ans);
	return 0;
}
