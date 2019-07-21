#include <cstdio>
#include <cmath>
/*
const int maxn = 100010;
int prime[maxn], pnum = 0;

bool isPrime(int n) {
	if(n <= 1) return false;
	int k = (int) sqrt(1.0 * n);
	for(int i = 2; i <= k; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
void findPrime(int n) {
	for(int i = 1; i <= n; i++){
		if(isPrime(i) == true) {
			prime[pnum++] = i;
		}
	}
}
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	findPrime(n);
	for(int i = 1; i < pnum; i++) {
		int dn = prime[i] - prime[i - 1];
		if(dn == 2)	sum++;
	}
	printf("%d\n", sum);
	return 0;
}*/
#include <cstdio>
#include <cmath>

bool isPrime(int n) {
	if(n <= 1) return false;
	int k = (int) sqrt(1.0 * n);
	for(int i = 2; i <= k; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 3; i + 2 <= n; i += 2) {
		if(isPrime(i) == true && isPrime(i + 2) == true) sum++;
	}
	printf("%d\n", sum);
	return 0;
}

