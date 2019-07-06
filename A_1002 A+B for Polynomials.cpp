#include <cstdio>

int main() {
	double list[1111] = {0};
	int count = 0, n;
	double a;
	scanf("%d" ,&count);
	for(int i = 0; i < count; i++) {
		scanf("%d %lf", &n, &a);
		list[n] += a;
	}
	scanf("%d" ,&count);
	for(int i = 0; i < count; i++) {
		scanf("%d %lf", &n, &a);
		list[n] += a;
	}
	count = 0;
	for(int i = 0; i < 1111; i++) {
		if(list[i] != 0) count++;
	}
	printf("%d", count);
	for(int i = 1110; i >= 0; i--) {
		if(list[i] != 0) printf(" %d %.1f", i, list[i]);
	}
	return 0;
}
