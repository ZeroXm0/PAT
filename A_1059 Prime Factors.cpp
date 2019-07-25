#include <cstdio>
#include <cmath>
const int maxn = 100001;
int prime[maxn], pnum = 0;
struct Factor {
	int x, cnt;
}fac[10];
bool isPrime(int n) {
	if(n == 1) return false;
	int sqr = (int) sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
void findPrime() {
	for(int i = 1; i < maxn; i++){
		if(isPrime(i) == true) prime[pnum++] = i;
	}
}
int main() {
	findPrime();
	int n, num = 0;
	scanf("%d", &n);
	if(n == 1) printf("1=1");
	else{
		printf("%d=", n);
		int sqr = (int) sqrt(1.0 * n);
		for(int i = 0; i < pnum && prime[i] <= sqr; i++) {
			if(n % prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n % prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if(n == 1) break;
		}
		if(n != 1) {
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for(int i = 0; i < num; i++) {
			if(i > 0) printf("*");
			int k = fac[i].cnt;
			int count = fac[i].x;
			printf("%d", count);
			if(k > 1) printf("^%d", k);
		}
	}
	return 0;
}
