#include <cstdio>
#include <cmath>
const int maxn = 10010;
bool num[maxn] = {false};
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int m, n, t;
	scanf("%d %d", &m, &n);
	t = m;
	while(isPrime(t) == false){
		t++;
	}
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		int v = k % t;
		int step = 0;
		while(step < t) {
			if(num[v] == false){
				num[v] = true;
				printf("%d", v);
				break;
			} else {
				step++;
				v = (k + step * step) % t;
			}
		} 
		if(step >= t) printf("-");
		if(i < n - 1) printf(" ");
		else printf("\n");
	} 
	return 0;
}
