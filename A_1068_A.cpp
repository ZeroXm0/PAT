#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		long long a,b,c;
		scanf("%lld %lld %lld", &a, &b, &c);
		//�ж�a+b�Ƿ����c��������Ҫע�����a+b������������a����0��b����0������ӵõ���ȴ��С�ڵ���0��˵�������������ʱ�϶���c����Ϊc�϶���long long�ķ�Χ�ڣ���
		//���aС��0��bС��0������ӵõ���ȴ�Ǵ��ڵ���0��˵���Ǹ���������ǿ϶���cС����������ͺ�ƽ������һ�������ﻹҪע��a+bҪ��ֵ��һ�������ٺ�c�Ƚϡ�
		//���ﲻ����a+b����res �������£��������£�����������dev���ǿ��Եģ�Ӧ����oj������ 
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
