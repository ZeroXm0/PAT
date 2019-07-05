#include <cstdio>
#include <cstring>

int main() {
	char str1[101],str2[101];
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1 > len2 ? len1 : len2; 
	char res[101]; 
	for(int i = 1; i <= len; i++){
		int A = i <= len1 ? str1[len1 - i] - '0' : 0;
		int B = i <= len2 ? str2[len2 - i] - '0' : 0;
		
		if(i % 2 != 0){//奇数 第一位为 len-1 
			int k =( A + B  ) % 13;
			if( k == 10){
				res[len - i] = 'J';
			}else if(k == 11){
				res[len - i] = 'Q';
			} else if(k == 12) {
				res[len - i] = 'K';
			}else{
				res[len - i] = k + '0';			
			}

		}else{
			res[len - i] =( B - A + 10)  % 10 + '0'; 
		}
	}
	printf("%s", res);
	
} 
