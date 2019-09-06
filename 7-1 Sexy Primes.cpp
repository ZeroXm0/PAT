#include <cstdio>
#include <cmath>
bool isPrime(int v) {
	if(v <= 1) return false;
	int sqr = (int)sqrt(1.0 * v);
	for(int i = 2; i <= sqr; i++) {
		if(v % i == 0) return false;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	if(isPrime(n) && isPrime(n - 6)) {
		printf("Yes\n%d\n", n - 6);
	} else if(isPrime(n) && isPrime(n + 6)) {
		printf("Yes\n%d\n", n + 6);
	} else {
		printf("No\n");
		int k = n + 1;
		while(k++){
			if(isPrime(k) && isPrime(k - 6)) {
				printf("%d\n", k);
				break;
			} else if(isPrime(k) && isPrime(k + 6)) {
				printf("%d\n", k);
				break;
			}
		} 
	}
	return 0;
}
