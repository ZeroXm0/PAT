#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10010;
const int maxc = 110;
int coin[maxn], d[maxn] = {0};
bool choice[maxn][maxc], flag[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}
	sort(coin + 1, coin + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		for(int v = m; v >= coin[i]; v--) {
			if(d[v] <= d[v - coin[i]] + coin[i]) {
				d[v] = d[v - coin[i]] + coin[i];
				choice[i][v] = 1;
			} else {
				choice[i][v] = 0;
			}
		}
	}
	if(d[m] != m) printf("No Solution");
	else {
		int k = n, num = 0, v = m;
		while(k >= 0) {
			if(choice[k][v] == 1) {
				flag[k] = true;
				v -= coin[k];
				num++;
			} else {
				flag[k] = false;
			}
			k--;
		}
		for(int i = n; i >= 1; i--) {
			if(flag[i]) {
				printf("%d", coin[i]);
				num--;
				if(num > 0) printf(" ");
			}
		}
		return 0;
	}
}
