#include <cstdio>
#include <cmath> 

int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int bottom = (int) sqrt(2.0 * (1 + n)) - 1;
	if( bottom % 2 == 0) bottom--;
	int re = n - ( (1 + bottom) * (1 + bottom) /2 - 1);//��ôд��Ϊ�˷����Լ���� 
	for(int j = bottom; j > 0; j -= 2){//jλ��ǰ�зǿ��ַ��� 
		for(int i = 0; i < (bottom - j) / 2; i++) printf(" ");
		for(int k = 0; k < j; k++) {
			if(k != j - 1) printf("%c", c);
			else printf("%c\n", c);
		} 
	} 
	for(int j = 3; j <= bottom; j += 2){//jλ��ǰ�зǿ��ַ��� ,�����ǣ��°벿�֣��ӵڶ��п�ʼ���������j=3 
		for(int i = 0; i < (bottom - j) / 2; i++) printf(" ");
		for(int k = 0; k < j; k++) {
			if(k != j - 1) printf("%c", c);
			else printf("%c\n", c);
		} 
	} 
	printf("%d", re);
	
	return 0;
	
}
