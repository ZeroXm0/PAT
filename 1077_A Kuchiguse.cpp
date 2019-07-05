#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void reverse(char s[] ){
	int len = strlen(s);
	for( int i = 0; i < len / 2 ;i++){
		char temp = s[i];
		s[i] = s[ len - i - 1];
		s[len - i - 1] = temp;
	}
}

int main() {
	int n,num = 0,minlen = 256;
	scanf("%d\n", &n);//注意换行符一定要加 
	char str[101][260];
	for(int i = 0 ; i < n; i++) {
		char charact[260];
		cin.getline(str[i], 260);
		reverse(str[i]);
        int len = strlen(str[i]);
        minlen = len < minlen ? len : minlen;//注意用最小长度比较
	}
	for( int i = 0; i < minlen; i++){
		char a = str[0][i];
		bool same = true;
		for ( int j = 1; j < n; j++){
			if(str[j][i] != a){
				same = false;
				break;
			}
		}
		if(same) num++;
		else break;//从不相同的位起不必再运算 
	}
	if( num ) {
		for(int i = num - 1; i >=0; i--){
			printf("%c", str[0][i]);
		}
	} else {
		printf("nai");
	}
	
	
	return 0;
} 
