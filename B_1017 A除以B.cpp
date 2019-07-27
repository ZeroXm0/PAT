#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1001;
struct bign{
	int d[maxn], len, r;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
		r = 0;
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
bign divide(bign a, int b) {
	bign c;
	c.len = a.len;
	int carry = 0;
	for(int i = a.len - 1; i >= 0; i--) {
		carry = carry * 10 + a.d[i];
		if(carry < b) c.d[i] = 0;//ע�⣺���ܳ�������Ϊ���� 
		else {
			c.d[i] = carry / b;
			carry = carry % b;
		}
	}
	c.r = carry;
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) c.len--;//���λ�����0��ȥ����λ����0������ȥ 
	return c; 
}
int main() {
	char str[maxn];
	int k;
	scanf("%s %d", str, &k);
	bign a = change(str);
	bign res = divide(a, k);
	for(int i = res.len - 1; i >= 0; i--) {
		printf("%d", res.d[i]);
		if(i == 0) printf(" %d\n", res.r);
	}
	return 0;
} 
