#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	char str[10000];
	cin.getline(str, 10000);
	int len = strlen(str);
	
	int res[10] = { 0 };
	
	for(int i = 0; i < len; i++) {
		res[ str[i] - '0' ]++;
	}
	for(int j = 0; j < 10; j++) {
		if( res[j] > 0) printf("%d:%d\n", j, res[j]);
	}
	return 0;
 }
