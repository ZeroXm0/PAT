#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 21;
struct bign {
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
bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
bool judge(bign a, bign b) {
	if(a.len != b.len) return false;
	int count[10] = {0};
	for(int i = 0; i < a.len; i++) {
		count[a.d[i]]++;
		count[b.d[i]]--;
	}
	for(int i = 0; i < 10; i++) {
		if(count[i] != 0) return false;
	}
	return true;
}
int main() {
	char str[21];
	cin.getline(str, 21);
	bign n = change(str);
	bign m = multi(n, 2);
	if(judge(n, m) == true) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for(int i = m.len - 1; i >= 0; i--) cout << m.d[i];
	return 0;
}
