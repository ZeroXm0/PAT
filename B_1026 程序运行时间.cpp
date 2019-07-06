#include <cstdio>

int main() {
	int c1,c2;
	scanf("%d %d", &c1, &c2);
	int ans = c2 - c1;
	if( ans % 100 >= 50) ans = ans / 100 + 1;
	else ans /= 100;
	
	int hh = ans / (60 * 60),mm = ans % (60 * 60) / 60, ss = ans % 60;
	printf("%02d:%02d:%02d\n" , hh, mm, ss);
	return 0;	
}
