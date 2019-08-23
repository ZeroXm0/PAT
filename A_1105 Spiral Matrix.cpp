#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10010;
bool cmp(int a, int b) {
	return a > b;
}
int ans[maxn][maxn];
int num[maxn];
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	if(N == 1) {
		printf("%d\n", num[0]);
		return 0;
	}
	sort(num, num + N, cmp);
	int m = (int)ceil(sqrt(1.0 * N));
	while(N % m != 0) {
		m++;
	}
	int n = N / m;
	int l = 1, r = n, u = 1, d = m;
	int cnt = 0, i = 1, j = 1;
	while(cnt < N) {
		while(cnt < N && j < r) {
			ans[i][j] = num[cnt++];
			j++;
		}
		while(cnt < N && i < d) {
			ans[i][j] = num[cnt++];
			i++;
		}
		while(cnt < N && j > l) {
			ans[i][j] = num[cnt++];
			j--;
		}
		while(cnt < N && i > u) {
			ans[i][j] = num[cnt++];
			i--;
		}
		l++, u++, r--, d--;
		i++, j++;
		if(cnt == N - 1) {
			ans[i][j] = num[cnt++]; 
		} 
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d", ans[i][j]);
			if(j < n) printf(" ");
			else printf("\n");
		}
	}
} 
