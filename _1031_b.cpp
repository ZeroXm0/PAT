#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {

	int wi[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char m[15] = { '1', '0', 'X', '9', '8','7', '6', '5', '4', '3', '2'};
	char res[100][17];
	int n;
	bool status = true;
	scanf("%d\n", &n);
	for(int k = 0; k < n; k++){
		int sum = 0, i;
		char str[20];
		cin.getline(str, 20);
		for( i = 0; i < 17; i++) {
			if( str[i] >= '0' && str[i] <= '9'){
				sum = sum + wi[i] * (str[i] - '0');
			}else{
				status = false;
				printf("%s\n", str);
				break;
			}
		}
		if( i == 17 ){
			int z = sum % 11;
			if( m[z] != str[17] ){
				status = false;
				printf("%s\n", str);
			} 
		}
	}
	if( status == true ) printf("All passed\n");
	return 0;
 } 
