#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
} 

int main() {
	int l, k,flag = -1;
	char n[1010];
	scanf("%d %d", &l, &k);
	getchar();
	cin.getline(n,1010);
	for(int i = 0; i <= l - k; i++) {
		int sum = 0;
		for(int j = i; j < i + k; j++) {
			sum = sum * 10 + n[j] - '0';
		}
		if(isPrime(sum) == true) {
			flag = i;
			break;
		} 
	}
	if(flag >= 0) {
		for(int i = flag; i < flag + k; i++) {
			printf("%d", n[i] - '0');
		}
	}else {
		
		printf("404");
	}
}
