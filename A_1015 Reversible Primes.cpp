#include <cstdio>
#include <cmath>
const int maxn = 100010;
int s[maxn];
bool isPrime(int n) {
	if(n <= 1) return false;
	int k = (int)sqrt(1.0 * n);
	for(int i = 2; i <= k; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	int n, d;
	while(scanf("%d", &n) && n > 0){
		scanf("%d", &d);
		if(isPrime(n) == false) printf("No\n");
		else {
			int num = 0;
			while(n) {
				s[num++] = n % d;
				n /= d;
			}
			for(int i = 0; i < num; i++) {
				n = n * d + s[i];
			}
			if(isPrime(n)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}
