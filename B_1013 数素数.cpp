#include <cstdio>
#include <cmath>
const int maxn = 10010;
int p[maxn], pnum = 1;
int m, n;
bool isPrime(int x) {
	if(x <= 1) return false;
	int k = (int)sqrt(1.0 * x);
	for(int i = 2; i <= k; i++) {
		if(x % i == 0) return false;
	}
	return true;
}
void findPrime() {
	int i = 1;
	while(pnum <= n) {
		if(isPrime(i) == true) {
			p[pnum++] = i;
		}
		i++;
	}
}
int main() {
	scanf("%d %d", &m, &n);
	findPrime();
	for(int i = m; i <= n; i++) {
		printf("%d", p[i]);
		if((i - m + 1) % 10 != 0 && i != n) printf(" ");
		else printf("\n");
	}
	return 0;
}
