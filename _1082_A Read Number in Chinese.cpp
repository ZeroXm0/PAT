#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char num[10][5] = {
	"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};
int main() {
	char str[15];
	cin.getline(str, 15);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if(str[0] == '-'){
		printf("Fu");
		left++;
	}
	while( left + 4 <= right) right -= 4;
	while( left < len ) {
		bool flag = false, isPrint = false;
		while( left <= right){
			if(left > 0 && str[left] == '0' ){
				flag = true;
			} else {
				if(flag == true) {
					printf(" ling");
					flag = false;
				}
				if(left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if(left != right) {
					printf(" %s", wei[right - left - 1]);
				}
			}
			
			left++;
		}
		if(isPrint == true && right != len - 1){
			printf(" %s", wei[(len - right - 1) / 4 + 2]);//除4后至少是1，如果是一就是万于是是+2 
		}
		right += 4;
	} 
	
	return 0;
} 

