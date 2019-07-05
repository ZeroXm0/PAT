#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


int main() {
	char str[101];
	cin.getline(str, 101);
	int len = strlen(str), sum = 0;
	for( int i = 0; i < len; i++) {
		sum += (str[i] - '0');
	}

	char yin[10][5] = {
	"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
	};
	int res[10],j = 0;
	while( sum != 0) {
		res[j++] = sum % 10;
		sum /= 10;
	}
	for(int i = j - 1; i >= 0; i--){
		printf("%s", yin[res[i]]);
		if(i != 0) printf(" ");
		else  printf("\n");
	}
	return 0;
}
