#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010];
int binarySearch(int left, int right, int key) {
	int mid;
	while(left <= right) {
		mid = (left + right) / 2;
		int sum = num[mid];
		if(sum == key) return mid;
		else if(sum > key) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	int i;
	for(i = 0; i < n; i++) {
		int key = m - num[i];
		int ans = binarySearch(0, n - 1, key);
		if(ans != -1 && i != ans) {
			printf("%d %d\n",num[i], key);
			break;
		}
	} 
	if(i == n) printf("No Solution\n");
	return 0;
}
