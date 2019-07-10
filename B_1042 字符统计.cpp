#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1010;

int main() {
	int hash[30] = {0};
	char str[maxn];
	cin.getline(str, maxn);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'a' && str[i] <=  'z') {
			hash[str[i] - 'a']++;
		}else if(str[i] >= 'A' && str[i] <= 'Z') {
			hash[str[i] - 'A']++;//-A+a是小写+26。-A是转化成小写 
		}
	}
	int k = 0;
	for(int i = 1; i < 26; i++) {
		if(hash[i] > hash[k]) k = i;
	} 
	printf("%c %d", k + 'a', hash[k]);
	return 0;
}
