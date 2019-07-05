#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		long long a,b,c;
		scanf("%lld %lld %lld", &a, &b, &c);
		//判断a+b是否大于c。这里需要注意的是a+b可能溢出，如果a大于0且b大于0，但相加得到的却是小于等于0的说明是正溢出，这时肯定比c大（因为c肯定在long long的范围内）。
		//如果a小于0且b小于0，但相加得到的却是大于等于0的说明是负溢出，这是肯定比c小。其他情况就和平常计算一样。这里还要注意a+b要赋值给一个变量再和c比较。
		//这里不能用a+b代替res ，查了下，测试了下，溢出情况下在dev中是可以的，应该是oj的问题 
		long long res = a + b;
		if(a > 0 && b > 0 && res <= 0){
			printf("Case #%d: true\n", i + 1);
		}else if (a < 0 && b < 0 && res >= 0){
			printf("Case #%d: false\n", i + 1);
		}else if( res > c){
			printf("Case #%d: true\n", i + 1);
		}else{
			printf("Case #%d: false\n", i + 1);
		}
	}
	return 0; 
} 
