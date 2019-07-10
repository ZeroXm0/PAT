#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100010;

int main() {
	bool hash[256];
	memset(hash, true, sizeof(hash));
	char str1[maxn], str2[maxn];
	cin.getline(str1, maxn);
	int len1 = strlen(str1);
	for(int i = 0; i < len1; i++) {
		if(str1[i] >= 'A' && str1[i] <= 'Z') str1[i] = str1[i] - 'A' + 'a';
		hash[str1[i]] = false;
	}
	cin.getline(str2, maxn);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; i++) {
		int j;
		if(str2[i] <= 'Z' && str2[i] >= 'A') {
			j = str2[i] - 'A' + 'a';
			if(hash[j] == true && hash['+'] == true){
				printf("%c", str2[i]);
			
			}
		} else if (hash[str2[i]] == true) {
			printf("%c", str2[i]);
		}
	}
	printf("\n");	
	return 0;
} 
