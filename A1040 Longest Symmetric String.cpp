#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1010;
int main() {
	int dp[maxn][maxn];
	char str[maxn];
	cin.getline(str, 1010);
	memset(dp, 0, sizeof(dp));
	int len = strlen(str);
	int ans = 1;
	for(int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if(i < len - 1) {
			if(str[i] == str[i + 1]) {
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for(int l = 3; l <= len; l++) {
		for(int i = 0; i + l - 1 < len; i++) {
			if(str[i] == str[i + l - 1] && dp[i + 1][i + l - 2] == 1) {
				dp[i][i + l - 1] = 1;
				ans = l;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} 
