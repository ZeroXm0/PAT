#include <stdio.h>

int main() {
	long long a,b,c,d,e,f;
	 scanf("%lld.%lld.%lld %lld.%lld.%lld" , &a, &b,&c,&d, &e,&f) ;
	 long long result = a * 17 * 29 + b * 29 + c + d * 17 * 29 + e * 29 + f;
	 long long g = result / (17 * 29);
	 long long s = result % (17 * 29) / 29;
	 result =  result % (17 * 29) % 29;
	 printf("%lld.%lld.%lld", g, s, result); 
	
	return 0;
}
