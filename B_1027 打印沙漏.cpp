#include <cstdio>
#include <cmath> 

int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int bottom = (int) sqrt(2.0 * (1 + n)) - 1;
	if( bottom % 2 == 0) bottom--;
	int re = n - ( (1 + bottom) * (1 + bottom) /2 - 1);//这么写是为了方便自己理解 
	for(int j = bottom; j > 0; j -= 2){//j位当前行非空字符数 
		for(int i = 0; i < (bottom - j) / 2; i++) printf(" ");
		for(int k = 0; k < j; k++) {
			if(k != j - 1) printf("%c", c);
			else printf("%c\n", c);
		} 
	} 
	for(int j = 3; j <= bottom; j += 2){//j位当前行非空字符数 ,正三角（下半部分）从第二行开始输出，所以j=3 
		for(int i = 0; i < (bottom - j) / 2; i++) printf(" ");
		for(int k = 0; k < j; k++) {
			if(k != j - 1) printf("%c", c);
			else printf("%c\n", c);
		} 
	} 
	printf("%d", re);
	
	return 0;
	
}
