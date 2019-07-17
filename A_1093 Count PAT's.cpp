#include <cstdio>
#include <cstring>
int p[100010], t[100010], mod = 1000000007;
int main() {
	char str[100010];
	scanf("%s", str);
	int len = strlen(str);
	if(str[0] == 'P') p[0] = 1; 
	for(int i = 1; i < len; i++) {
		if(str[i] != 'P') p[i] = p[i - 1];
		else p[i] = p[i - 1] + 1;
	}//p ´Ó1~n¼ÇÂ¼
	int ans = 0;
	for(int i = len - 1; i >= 0; i--) {
		if(str[i] == 'T') t[i] = t[i + 1] + 1;
		else t[i] = t[i + 1];
		if(str[i] == 'A') {
			ans = (ans + t[i] * p[i]) % mod;
		}
	} 
	printf("%d", ans);
	return 0;
}
