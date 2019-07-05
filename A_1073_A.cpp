#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str[10010];//9999byte的科学计数法超过10000位，符号小数点字母占位多 
	cin.getline(str,10010);
	int len = strlen(str);
	if(str[0] == '-') printf("-");
	int pos = 0;//记录E的位子
	while(str[pos] != 'E') {
		pos++;
	}
	int exp = 0;//记录指数
	for(int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	//指数位0的情况必须考虑
	if(exp == 0){
		for(int i = 1; i < pos; i++){
			printf("%c", str[i]);
		}
	} 
	
	if(str[pos + 1 ] == '-'){
		printf("0.");
		for(int i = 0; i < exp - 1; i++) {//小数点前移exp位，共有 exp-1个0 
			printf("0");
		}
		printf("%c", str[1]);
		for(int i = 3; i < pos; i++) {
			printf("%c", str[i]);
		}
	}else{
		for(int i = 1; i < pos; i++) {//小数点后移exp-1位 ，小数点前共3个字符个 ,还因此小数点在exp+3原标号第exp+2的位子上 
			if(str[i] == '.') continue;//遇到小数点跳过 
			printf("%c", str[i]);
			if(i == exp + 2 && pos - 3 != exp) {//pos减3就是小数点后的位数，如果和运动位数相同，则无需加小数点 
				printf("."); 
			}
		}
		for(int i = 0; i < exp - (pos - 3); i++) {
			printf("0");//如果指数较大，输出多位0 
		}
    }
	return 0;
} 
