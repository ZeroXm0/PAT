#include <cstdio>

int main() {
	int n;
	double v, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &v);
		sum += v * (i + 1) * (n - i);
	}
	printf("%.2f\n", sum);
	return 0;
}
