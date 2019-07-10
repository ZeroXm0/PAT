#include <cstdio>
int num[100009],bets[10009] = {0},status = 0;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		bets[num[i]]++;
	}
	for(int i = 0; i < n; i++) {
		if(bets[num[i]] == 1) {
			printf("%d",num[i]);
			status = 1;
			break;
		}
	}
	
	if(!status) printf("None");
	return 0;
} 
