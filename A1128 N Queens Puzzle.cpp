#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int k, n;
	scanf("%d", &k);
	while(k--) {
		scanf("%d", &n);
		vector<int> queen(n + 1);
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &queen[i]);
			for(int j = 1; j < i; j++) {
				if(queen[i] == queen[j]) flag = false;
				if(abs(i - j) == abs(queen[i] - queen[j])) flag = false;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
