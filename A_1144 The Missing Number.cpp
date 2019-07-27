#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100010;
int main() {
	int n, min = 0x3fffffff;
	bool num[maxn] = {false};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if(k > 0 && k < maxn){
			num[k] = true;
		}
	}
	int i = 1;
	while(num[i]) i++;
	printf("%d", i);
	return 0;
}
