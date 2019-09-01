#include <cstdio>
int main() {
	int n, ans, str;
	scanf("%d", &n);
	while(n--) {
		int idx = 0, num[15];
		scanf("%d", &ans);
		str = ans;
		while(str) {
			num[idx++] = str % 10;
			str /= 10;
		}
		int len = idx / 2, a = 0, b = 0;
		for(int i = len - 1; i >= 0; i--) {
			a = a * 10 + num[i];
			b = b * 10 + num[i + len];
		}
		if(a * b == 0 || ans % (a * b)) printf("No\n");		//特别注意被除数为0的情况 
		else printf("Yes\n");
	}
	return 0;
} 
