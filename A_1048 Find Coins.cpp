#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;

int main() {
	int coin;
	int hash[maxn] = {0};
	int n,m; 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &coin);
		++hash[coin];
	}
	for(int i = 1; i < m; i++) {
		if(hash[i] && hash[m - i] ) {
			if(i == m - i && hash[i] <= 1) continue;
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}

