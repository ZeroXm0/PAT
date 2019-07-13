#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long LL;
using namespace std;
LL lnf = (1LL << 63) - 1; //LL 最大值 
//找出进制下界
int findmin( char str[]) {
	int radix = -1;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		int num;
		if(str[i] >= '0' && str[i] <= '9') num = str[i] - '0';
		else if(str[i] >= 'a' && str[i] <= 'z') num = str[i] - 'a' + 10; 
		if(num > radix) radix = num;
	}
	return radix + 1;
} 

LL translate (char n[], LL r,LL t) {//返回十进制数 
	int len = strlen(n);
	LL sum = 0;
	for(int i = 0; i < len; i++) {
		int num;
		if(n[i] >= '0' && n[i] <= '9') num = n[i] - '0';
		else if(n[i] >= 'a' && n[i] <= 'z') num = n[i] - 'a' + 10; 
		sum = sum * r + num;
		if(sum < 0 || sum > t) return -1;
	}
	return sum;
}

int cmp( char n2[], LL r, LL t) {
	int len = strlen(n2);
	LL num = translate(n2, r, t);
	if(num < 0) return 1;//溢出，n2大 
	if(t > num) return -1;
	else if(t == num) return 0;
	else return 1;
}
LL  binarySearch(char n2[], LL left, LL right, LL t) {
	LL mid;
	while(left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if(flag == 0) return mid;
		else if(flag > 0) right = mid - 1;
		else left = mid + 1;
	} 
	return -1;
}
int main() {
	char n1[15], n2[15], temp[15]; 
	int tag, radix;
	scanf("%s%s%d%d", n1, n2, &tag, &radix);
	if(tag == 2) {
		strcpy(temp, n1);
		strcpy(n1, n2);
		strcpy(n2, temp);
	}
	LL t = translate(n1, radix, lnf);
	LL left = findmin(n2);
	LL right = max(left, t) + 1;
	LL ans = binarySearch(n2, left, right, t);
	if(ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0; 
} 
