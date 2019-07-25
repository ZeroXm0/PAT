#include <cstdio>
#include <cmath>
typedef long long ll;
int ansI, anslen;
int main(){
	ll n;
	scanf("%lld", &n);
	ll sqr = sqrt(1.0 * n);
	for(ll i = 2; i <= sqr; i++) {
		ll temp = 1.0, j = i;
		while(1) {
			temp *= j;
			if(n % temp != 0) break;
			if(j - i + 1 > anslen) {
				ansI = i;
				anslen = j - i + 1;
			}
			j++;
		}
	}
	if(anslen == 0) printf("1\n%lld", n);
	else {
		printf("%d\n", anslen);
		for(int i = ansI; i < ansI + anslen; i++) {
			if(i > ansI) printf("*");
			printf("%d", i);
		}
	}
}
