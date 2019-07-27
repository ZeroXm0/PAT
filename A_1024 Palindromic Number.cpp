#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1000;// 注意10位数。每布可能增加一位。100次最大可以增加100位，因此位数位设为大于 110 
struct bign{
	int d[maxn], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
bign oper(bign a) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++) {
		int temp = a.d[i] + a.d[a.len - i - 1] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}
bool judge(bign c) {
	int n = c.len / 2;
	for(int i = 0; i <= n; i++) {
		if(c.d[i] != c.d[c.len - i - 1]) return false;
	}
	return true;
}
int main() {
	char str[maxn];
	int step, i;
	scanf("%s %d", str, &step);
	bign a = change(str);
	for(i = 0; i < step && judge(a) == false; i++) {
		a = oper(a);
	}
	for(int j = a.len - 1; j >= 0; j--) cout << a.d[j];
	printf("\n%d\n", i);
	return 0;
}
