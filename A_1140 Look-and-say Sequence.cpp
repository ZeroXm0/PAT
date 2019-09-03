#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
	string str;
	int n;
	cin >> str >> n;
	for(int i = 1; i < n; i++) {
		string s;
		for(int j = 0; j < str.length(); ) {	//必须从0开始，初始只有一个 
			int d;
			for(d = j; d < str.length() && str[d] == str[j]; d++);
			s += str[j];
			s += d - j + '0';
			j = d;
		}
		str = s;
	}
	cout << str << endl;
	return 0;
} 
