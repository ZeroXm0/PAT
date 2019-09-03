#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
/* 
原来用二维数组记录是否是朋友 
根据柳神代码，使用map<int, bool> arr 替代二维数组可避免内存超限 
*/
const int maxn = 10010;
vector<int> v[maxn];
int n, m, k;		
map<int, bool> arr;				//记录是否是朋友
struct node{
	int c, d;
};
bool cmp(node a, node b) {
	if(a.c != b.c) return a.c < b.c;
	return a.d < b.d; 
}
int strToInt(string s) {
	int sum = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '-') continue;
		sum = sum * 10 + s[i] - '0'; 
	}
	sum = s[0] == '-' ? sum * -1 : sum;
	return sum;
}
int main() {
	cin >> n >> m;
	int cnt = 1;
	for(int i = 1; i <= m; i++) {
		string f1, f2;
		cin >> f1 >> f2;
		if(f1.length() == f2.length()) {
			v[abs(strToInt(f1))].push_back(abs(strToInt(f2)));
			v[abs(strToInt(f2))].push_back(abs(strToInt(f1)));
		}
		arr[abs(strToInt(f2)) * 10000 + abs(strToInt(f1))] = arr[abs(strToInt(f1)) * 10000 + abs(strToInt(f2))] = true; 
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		vector<node> res;
		int first, second;
		cin >> first >> second;
		int ans = 0;
		for(int i = 0; i < v[abs(first)].size(); i++) {
			int c = v[abs(first)][i];
			for(int j = 0; j < v[abs(second)].size(); j++) {
				int d = v[abs(second)][j];
				if(c == abs(second) || d == abs(first)) continue;
				if(arr[c * 10000 + d]) {
					ans++;
					res.push_back(node{c, d});
				}
			}
		}
		printf("%d\n", ans);
		sort(res.begin(), res.end(), cmp);
		for(int j = 0; j < res.size(); j++) {
			printf("%04d %04d\n", res[j].c, res[j].d);
		}
	}
	return 0;
}
