#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;
const int maxn = 110;
bool stuckBroke[256];
map<char, int> isStuck;
int main() {
	int k;
	scanf("%d", &k);
	string str;
	cin >> str;
	int cnt = 1;
	char pre = '#';
	str = str + '#';
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == pre) {
			cnt++;
		} else {
			if(cnt % k != 0) {
				stuckBroke[pre] = true;
			}
			cnt = 1;
		}
		if(i != str.length() - 1) isStuck[str[i]] = (cnt % k == 0);
		pre = str[i];
	}
	for(int i = 0; i < str.length() - 1; i++) {
		if(stuckBroke[str[i]] == true) isStuck[str[i]] = false;
	}
	set<char> v;
	for(int i = 0; i < str.length() - 1; i++) {
		if(isStuck[str[i]] && v.find(str[i]) == v.end()) {
			printf("%c", str[i]);
			v.insert(str[i]);
		}
	}
	printf("\n");
	int i = 0;
	while(i < str.length() - 1) {
		printf("%c", str[i]);
		if(isStuck[str[i]]) i += k;
		else i++;
	}
	printf("\n");
	return 0;
} 
