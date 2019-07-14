#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n,p,a[maxn];
int binarySearch(int x, long long m) {
	if(a[n - 1]  <= m) return n;
	int left = x + 1, right = n - 1, mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(a[mid] <= m) left = mid + 1;
		else right = mid;
	}
	return left;
}

int main() {
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	} 
	sort(a, a + n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
} 
