#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	bool hash[10010] = {false};//3n+1猜想数字可以很大 
	int k, n[maxn];
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &n[i]);
		int num = n[i];
		while(num > 1) {
			if(num % 2 == 0) {
				num /= 2;
			} else {
				num = (num * 3 + 1) / 2;
			}
			hash[num] = true;
		}
	}
	int  count = 0;
	for(int i = 0; i < k; i++) {
		if(hash[n[i]] == false) count++;
	}
	sort(n, n + k,cmp);
	for(int i = 0; i < k;  i++) {
		if(hash[n[i]] == false){
			printf("%d", n[i]);
			count--;
			if(count != 0) printf(" ");
		} 
	}
	return 0;
}
