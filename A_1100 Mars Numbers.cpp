#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<string, int> theNum;
bool check(char c) {
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	return false; 
}
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	while(i < str.length()){		//接下来每一步都后移。所以都要判断i 小于长度 
		string word;
		while(i < str.length() && check(str[i]) == true) {			// 长度内。且是数字或字母。则属于本单词 
			if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;		//大写转小写 
			word += str[i];
			i++;
		}
		if(word != "") {		//字符串比较 "" ，找到单词 
			if(theNum.find(word) == theNum.end()) theNum[word] = 1;
			else theNum[word]++;
		}
		while(i < str.length() && check(str[i]) == false) i++;	//跳过非单词 
	}
	string ans;
	int max = 0;
	for(map<string, int>::iterator it = theNum.begin(); it != theNum.end(); it++) {
		if(it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << max << endl;
	return 0;
}
