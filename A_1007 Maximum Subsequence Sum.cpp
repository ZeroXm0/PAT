#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int main() {
	int k, num[maxn], sum[maxn];
	scanf("%d", &k);
	bool flag = false; 
	for(int i = 0; i < k; i++) {
		scanf("%d", &num[i]);
		if(num[i] >= 0) flag = true;			//考虑特殊情况全为负数 
	}
	if(flag == false) {
		printf("0 %d %d\n", num[0], num[k - 1]);
	} else {
		sum[0] = num[0];
		int theM = sum[0], mark = 0;
		for(int i = 1; i < k; i++) {
			sum[i] = max(num[i], num[i] + sum[i - 1]);
			if(sum[i] > theM) {
				theM = sum[i];
				mark = i;
			}
		}
		printf("%d ", sum[mark]);
		int ans = 0, i = mark;
		do {
			ans += num[i--];
		} while (ans < sum[mark]);
		printf("%d %d\n", num[i + 1], num[mark]);
	}
	return 0;
} 
