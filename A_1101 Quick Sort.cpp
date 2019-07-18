#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 0x3fffffff;
int a[maxn], ans[maxn], leftMax[maxn], rightMin[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int num = 0;
	leftMax[0] = 0;
	for(int i = 1; i < n; i++) {
		leftMax[i] = max(leftMax[i - 1], a[i - 1]);
	}
	rightMin[n - 1] = INF;
	for(int i = n - 2; i >= 0; i--) {
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);
	}
	for(int i = 0; i < n; i++) {
		if(a[i] > leftMax[i] && a[i] < rightMin[i]) ans[num++] = a[i];
	}
	printf("%d\n", num);
	for(int i = 0; i < num; i++) {
		printf("%d", ans[i]);
		if(i != num - 1) printf(" ");
	}
	return 0;
} 
