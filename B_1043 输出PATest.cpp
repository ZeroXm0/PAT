#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10010;
char dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int main() {
	int hash[6] = {0};
	char str[maxn];
	cin.getline(str, maxn);
	int len = strlen(str), count = 0;
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < 6; j++) {
			if(str[i] == dict[j]) {
				hash[j]++;
				count++;
			} 
		}
	}
	while(count > 0) {
		for(int i = 0; i < 6; i++) {
			if(hash[i] != 0){
				printf("%c", dict[i]);
				hash[i]--;
				count--;
			}
		}
	}
	return 0;
}
