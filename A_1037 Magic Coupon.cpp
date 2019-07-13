#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int c[100010], p[100010];
	int nc, np, sum = 0;
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; i++) {
		scanf("%d", &p[i]);
	}
	
	sort(c, c + nc);
	sort(p, p + np);
	int i = 0, j = 0;
	while(i < nc && j < np && c[i] < 0 && p[i] < 0){
		sum += c[i] * p[i];
		i++;
	}
	
	i = nc - 1, j = np - 1;
	while(i >= 0 && j >= 0 && c[i] > 0 && p[j] > 0) {
		sum += c[i] * p[j];
		i--, j--;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
