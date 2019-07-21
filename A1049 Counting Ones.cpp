#include <cstdio>
int main() {
	int n, a = 1, left, now, right, sum = 0;
	scanf("%d", &n);
	while(n / a != 0) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if(now == 0) sum += left * a;
		else if(now == 1) sum += left * a + right + 1;
		else sum += (left + 1) * a;
		a *= 10;
	}
	printf("%d\n", sum);
	return 0;
} 
