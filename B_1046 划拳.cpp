#include <cstdio>

int main() {
	int n, numa = 0, numb = 0;
	scanf("%d", &n);
	while(n--){
		int a, b, a1, b1;
		scanf("%d %d %d %d", &a, &a1, &b, &b1);
		int c = a + b;
		if( a1 == c && b1 != c){
			numb++;
		}else if( b1 == c && a1 != c){
			numa++;
		}
	}
	printf("%d %d", numa, numb);
	return 0;
	
}
