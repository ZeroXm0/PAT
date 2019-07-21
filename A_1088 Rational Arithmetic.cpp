#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
} 
struct Fraction{
	ll up, down;
}a, b, res;
Fraction simply(Fraction a) {
	if(a.down < 0) {
		a.up *= -1;
		a.down *= -1;
	} 
	if(a.up == 0) a.down = 1;
	else {
		ll d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
Fraction add(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.down + b.up * a.down;
	res.down = a.down * b.down;
	return simply(res);
}
Fraction deduce(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.down - b.up * a.down;
	res.down = a.down * b.down;
	return simply(res);
}
Fraction mul(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return simply(res);
}
Fraction mod(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.down;
	res.down = a.down * b.up;
	return simply(res);
}
void printRes(Fraction res) {
	res = simply(res);
	if(res.up < 0) printf("(");
	if(res.down == 1) printf("%lld", res.up);
	else if(abs(res.up) > res.down) {
		printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
	} else {
		printf("%lld/%lld", res.up, res.down);
	}
	if(res.up < 0) printf(")");
}

int main() {
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//+
	printRes(a);
	printf(" + ");
	printRes(b);
	printf(" = ");
	printRes(add(a, b));
	printf("\n");
	//-
	printRes(a);
	printf(" - ");
	printRes(b);
	printf(" = ");
	printRes(deduce(a, b));
	printf("\n");
	//*
	printRes(a);
	printf(" * ");
	printRes(b);
	printf(" = ");
	printRes(mul(a, b));
	printf("\n");
	// /
	printRes(a);
	printf(" / ");
	printRes(b);
	printf(" = ");
	if(b.up == 0) printf("Inf\n");
	else {
		printRes(mod(a, b));
		printf("\n");
	}
	return 0;
}
