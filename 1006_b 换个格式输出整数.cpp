#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int ans[4];
	int num = 0;
	do{
		ans[num++] = n % 10;
		n /= 10;
	}while(n != 0);
	
	for(int i = num - 1; i >= 0; i--) {
		if(i == 0){
			for(int j = 0; j < ans[i]; j++) {
				printf("%d", j + 1);
			}
		} else if ( i == 1 ) {
			for(int j = 0; j < ans[i]; j++){
				printf("S");
			}
		} else {
			for(int j = 0; j < ans[i]; j++){
				printf("B");
			}
		}
	} 
	return 0; 
}
