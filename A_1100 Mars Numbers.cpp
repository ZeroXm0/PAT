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
	while(i < str.length()){		//������ÿһ�������ơ����Զ�Ҫ�ж�i С�ڳ��� 
		string word;
		while(i < str.length() && check(str[i]) == true) {			// �����ڡ��������ֻ���ĸ�������ڱ����� 
			if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;		//��дתСд 
			word += str[i];
			i++;
		}
		if(word != "") {		//�ַ����Ƚ� "" ���ҵ����� 
			if(theNum.find(word) == theNum.end()) theNum[word] = 1;
			else theNum[word]++;
		}
		while(i < str.length() && check(str[i]) == false) i++;	//�����ǵ��� 
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
