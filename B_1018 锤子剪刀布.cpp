#include <cstdio>
#include <cstring>

int change(char c) {
	if(c == 'B') return 0;
	if(c == 'C') return 1;
	if(c == 'J') return 2;
} 

int main() {
	int n,k1,k2;
	char res[3] = {'B','C','J'};
	int time_a[3] = {0}, time_b[3] = {0};
	int a_win[3] = {0}, b_win[3] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		char a,b;
		getchar();//吸收空格，scanf %c下会读入换行符\n 
		scanf("%c %c", &a, &b);
		k1 = change(a);
		k2 = change(b);
		if( (k1 + 1) % 3 == k2 ){
			time_a[0]++;
			time_b[2]++;
			a_win[k1]++;
		}else if( k1 == k2) {
			time_a[1]++;
			time_b[1]++;
		}else{
			time_a[2]++;
			time_b[0]++;
			b_win[k2]++;
		}
	}
	printf("%d %d %d\n", time_a[0], time_a[1], time_a[2]);
	printf("%d %d %d\n", time_b[0], time_b[1], time_b[2]);	
	int win_a = 0, win_b = 0;
	for(int i = 0; i < 3; i++) {
		win_a = a_win[i] > a_win[win_a]? i : win_a;
		win_b = b_win[i] > b_win[win_b]? i : win_b;
	}
	printf("%c %c\n", res[win_a], res[win_b]); 
	return 0;
}
