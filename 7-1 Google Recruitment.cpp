#include <cstdio>
#include <cmath>
#include <string>
#include <iostream> 
using namespace std;
bool isPrime(int a) {
	if(a <= 1) return false;
	int sqr = (int)sqrt(1.0 * a);
	for(int i = 2; i <= sqr; i++) {
		if(a % i == 0) return false;
	}
	return true;
}
int strToInt(string s) {
	int sum = 0;
	for(int i = 0; i < s.length(); i++) {
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}
int main() {
	int l, k;
	scanf("%d%d", &l, &k);
	string str;
	cin >> str;
	int m;
	string s;
	for(int i = 0; i <= l - k; i++) {
		s = str.substr(i, k);
		m = strToInt(s);
		if(isPrime(m)) {
			break;
		}
	}
	if(isPrime(m)) cout << s << endl;
	else cout << "404" << endl;
	return 0;
}
