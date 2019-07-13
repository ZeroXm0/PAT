#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main() {
	int n, num,ans = 0;//num 标记自己所在位子 
	scanf("%d", &n);
	int left = n - 1;//表示不再最终位子上的数字个数（除0外） 
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0) left--;
	}
	int k = 1;//除0外不在最终位子上的最小数字 
	while(left > 0) {
		if(pos[0] == 0){//如果0在0位上，与一个不在最终位子上的数交换 
			while(k < n) {
				if(pos[k] != k){
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0] != 0) {//0不在0位上，就与其所在位子的数字交换 
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
