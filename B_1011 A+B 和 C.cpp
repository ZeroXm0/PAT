#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long long d = a + b;
		if(d > c) {
			printf("Case #%d: true\n", i + 1);
		} else {
			printf("Case #%d: false\n", i + 1);
		}
	}
	
	return 0; 
}
