#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 1010;
int m, n, s;
int main() {
	string str;
	cin >> m >> n >> s;
	bool flag = false;
	map<string, int> win;;
	for(int i = 1; i <= m; i++) {
		cin >> str;
		if(i == s){
			if(win[str] > 0) s++;
			if(win[str] == 0) {
				cout << str << endl;
				win[str]++;
				s += n;
				flag = true;
			}
		}
	}
	
	if(flag == false) {
		printf("Keep going...\n");
	}
	return 0;
}
