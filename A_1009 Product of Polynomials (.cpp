#include <cstdio>

struct Poly {
	int exp;
	double cof;
} poly[1001];

double a[2001];//全局变量静态分配内存，局部变量动态创建栈（如果数据过大，可能会造成溢出）
int main() {
	int count = 0, n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int e;
		double c;
		scanf("%d %lf", &e, &c);
		for(int j = 0; j < n; j++) {
			a[e + poly[j].exp] += (c * poly[j].cof);
		}
	}
	for(int i = 0; i < 2001; i++) {
		if(a[i] != 0.0) count++;
	}
	printf("%d", count);
	for(int i = 2000; i >=0; i--) {
		if(a[i] != 0.0) {
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}
