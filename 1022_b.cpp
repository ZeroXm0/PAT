#include <cstdio>

int main() {
	int a, b , d;
	scanf("%d %d %d", &a, &b, &d);
	int c = a + b;
	int res[31], count = 0;
	do {
		res[count] = c % d;
		c = c / d;
		count++;
	}while( c != 0);
	for( int i = count - 1; i >= 0; i--){
		printf("%d", res[i]);
	}
	return 0;
}
