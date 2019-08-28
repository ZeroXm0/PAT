#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL sum = 0, left = 0;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	int n1 = n / 2, n2 = n - n1;
	sort(num.begin(), num.end());
	for(int i = 0; i < n; i++) {
		sum += num[i];
		if(i < n1) {
			left += num[i];
		}
	} 
	LL ans = sum - 2 * left;
	printf("%d %d\n", n2 - n1, ans);
	return 0;
} 
