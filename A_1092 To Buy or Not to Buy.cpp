#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int change (char a) {
	if( a>= '0' && a <= '9') return a - '0';
	if( a >= 'a' && a <= 'z') return a - 'a' + 10;
	if( a >= 'A' && a <= 'Z') return a - 'A' + 36;
}

int main() {
	char sell[1010], buy[1010];
	cin.getline(sell, 1010);
	cin.getline(buy, 1010);
	int len1 = strlen(sell);
	int len2 = strlen(buy);
	int Hash[80] = {0};
	int miss = 0;//缺少的个数 
	for(int i = 0; i < len1; i++){
		int id = change(sell[i]);
		Hash[id]++;
	}
	
	for(int i = 0; i < len2; i++) {
		int id = change(buy[i]);
		Hash[id]--;
		if(Hash[id] < 0) miss++; 
	}
	if(miss > 0) printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	return 0;
}
