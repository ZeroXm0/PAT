#include <cstdio>
#include <algorithm>
using namespace std;
int num[10];

int main() {
	int n = 0;
	while (n < 10) {
		scanf("%d", &num[n]);
		n++;
	}
	for(int i = 1; i < 10; i++) {
		if(num[i] != 0){
			printf("%d", i);
			num[i]--;
			break; 
		}
	}
	for(int i = 0; i < 10; i++) {
		while(num[i]) {
			printf("%d", i);
			num[i]--;
		}
	}
	printf("\n");
	return 0;
}
