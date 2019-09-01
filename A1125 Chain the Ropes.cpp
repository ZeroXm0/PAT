#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int rope[maxn], n;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &rope[i]);
	}
	sort(rope, rope + n);		//哈夫曼编码思想，由小加到大，最后得到的就是最大的
	int ans = rope[0];
	for(int i = 1; i < n; i++) {
		ans = (ans + rope[i]) / 2;
	} 
	printf("%d\n", ans);
	return 0;
} 
