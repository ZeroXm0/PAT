#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}
struct Fraction {
	ll up;
	ll down;
};
Fraction reduceFraction(Fraction a) {
	if(a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
	if(a.up == 0) {
		a.down = 1;
	} else {
		ll d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
Fraction add(Fraction a, Fraction b) {
	Fraction res;
	res.up =  a.up * b.down + b.up * a.down;
	res.down = a.down * b.down;
	return reduceFraction(res);
}
void showFraction(Fraction res) {
	reduceFraction(res);
	if(res.down == 1) printf("%lld\n", res.up);
	else if(abs(res.up) > res.down) {
		printf("%lld %lld/%lld\n", res.up / res.down, abs(res.up) % res.down, res.down);
	} else {
		printf("%lld/%lld\n", res.up, res.down);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	Fraction sum, temp;
	for(int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showFraction(sum);
	return 0;
}
