#include <cstdio>
const int INF = 0x7fffffff;
const int maxn = 1000010;
int n1, n2;
int num1[maxn];
int main() {
	scanf("%d", &n1);
	for(int i = 0; i < n1; i++) {
		scanf("%d", &num1[i]);
	}
	num1[n1] = INF;
	scanf("%d", &n2);
	int num = (n1 + n2 + 1)  / 2;  //找出是第几个
	int k = 0, temp, count = 0;
	for(int i = 0; i < n2; i++) {
		scanf("%d", &temp);
		while(num1[k] < temp) {
			count++;
			if(count == num){
				printf("%d", num1[k]);
				return 0;
			}
			k++;
		}
		count++;
		if(count == num) {
			printf("%d", temp);
			return 0;
		}
	}
	while(count < num){
		count++;
		k++;
	}
	printf("%d", num1[k - 1]);
	return 0;
} 
