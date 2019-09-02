#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}
string getOri(string s1, string s2) {
	string s = s1;
	int len = s1.length(), ret = 0;		//ret记录进位 
	for(int i = len - 1; i >= 0; i--) {
		int add = s1[i] - '0' + s2[i] - '0' + ret;
		s[i] = add % 10 + '0';
		ret = add / 10;
	}
	if(ret) s = "1" + s;
	return s;
}
int main() {
	string s1, str;
	int n = 10;
	cin >> str;
	if(str == rev(str)) {			//考虑初始即是回文 
		cout << str << " is a palindromic number." << endl;
		return 0;
	}
	while(n--) {
		s1 = str;
		str = getOri(s1, rev(s1));
		cout << s1 << " + " << rev(s1) << " = " << str << endl;
		if(str == rev(str)){
			cout << str << " is a palindromic number." << endl;
			return 0;
		}
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
