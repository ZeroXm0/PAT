#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	char str[10010];//9999byte�Ŀ�ѧ����������10000λ������С������ĸռλ�� 
	cin.getline(str,10010);
	int len = strlen(str);
	if(str[0] == '-') printf("-");
	int pos = 0;//��¼E��λ��
	while(str[pos] != 'E') {
		pos++;
	}
	int exp = 0;//��¼ָ��
	for(int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	//ָ��λ0��������뿼��
	if(exp == 0){
		for(int i = 1; i < pos; i++){
			printf("%c", str[i]);
		}
	} 
	
	if(str[pos + 1 ] == '-'){
		printf("0.");
		for(int i = 0; i < exp - 1; i++) {//С����ǰ��expλ������ exp-1��0 
			printf("0");
		}
		printf("%c", str[1]);
		for(int i = 3; i < pos; i++) {
			printf("%c", str[i]);
		}
	}else{
		for(int i = 1; i < pos; i++) {//С�������exp-1λ ��С����ǰ��3���ַ��� ,�����С������exp+3ԭ��ŵ�exp+2��λ���� 
			if(str[i] == '.') continue;//����С�������� 
			printf("%c", str[i]);
			if(i == exp + 2 && pos - 3 != exp) {//pos��3����С������λ����������˶�λ����ͬ���������С���� 
				printf("."); 
			}
		}
		for(int i = 0; i < exp - (pos - 3); i++) {
			printf("0");//���ָ���ϴ������λ0 
		}
    }
	return 0;
} 
