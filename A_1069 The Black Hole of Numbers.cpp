#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans[5];
int toNum(int num[]) {
	int sum = 0;
	for(int i = 0; i < 4; i++) {
		sum = sum * 10 + num[i];
	}
	return sum;
}
bool cmp(int a, int b) {
	return a > b;
}
int toArray(int n) {
	int j = 0;
	while(n) {
		ans[j++] = n % 10;
		n /= 10;
	}
	return j;
}
int main() {
	int n, max, min;
	scanf("%d", &n);
	do{
		int j = toArray(n);
		sort(ans, ans + j);
		min = toNum(ans);
		sort(ans, ans + j, cmp);
		max = toNum(ans);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
	}while(n != 0 && n != 6174);
	return 0;
} 
