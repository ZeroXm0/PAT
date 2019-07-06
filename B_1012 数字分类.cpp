#include <cstdio>

int main() {
	int n,num;
	scanf("%d", &n);
	int a1 = 0, count1 = 0, a2 = 0, count2 = 0, a3 = 0, count3 = 0,a4 = 0, count4 = 0, a5 = 0, count5 = 0;
	while(n--){
		scanf("%d", &num);
		int a = num % 5; 
		if(a == 0 && num % 2 == 0) {
			a1 += num;
			count1++;
		}else if( a == 1 ) {
			if(count2 % 2 != 0 ){
				a2 -= num;
			}else {
				a2 += num;
			}
			count2++;
		}else if( a == 2 ) {
			a3++;
			count3++;
		}else if( a == 3 ) {
			a4 += num;
			count4++;
		}else if( a == 4 ) {
			a5 = a5 < num ? num : a5;
			count5++;
		}
	}
	float res4 = (float) a4 / count4;
	if(count1 != 0) printf("%d ", a1);
	else printf("N ");
	if(count2 != 0) printf("%d ", a2);
	else printf("N ");
	if(count3 != 0) printf("%d ", a3);
	else printf("N ");
	if(count4 != 0) printf("%.1lf ", res4);
	else printf("N ");
	if(count5 != 0) printf("%d", a5);
	else printf("N");
	return 0;
}
