#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 100010;
int n, m;
vector<string> ori,alumni;
string id;
map<string, bool> hashAlu;
bool cmp(string a, string b) {
	string s1 = a.substr(6, 8);
	string s2 = b.substr(6, 8);
	return s1 < s2;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> id;
		hashAlu[id] = true;
	}
	cin >> m;
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		cin >> id;
		if(hashAlu[id]) {
			cnt++;
			alumni.push_back(id);
		} else {
			ori.push_back(id);
		}
	}
	printf("%d\n", cnt);
	if(cnt) {
		sort(alumni.begin(), alumni.end(), cmp);
		cout << alumni[0] << endl;
	} else {
		sort(ori.begin(), ori.end(), cmp);
		cout << ori[0] << endl;
	}
	return 0;
} 
