#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b) {
	return a + b < b + a;//a拼接上b 小于 b拼接上a 那就a在前 
} 
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) cin >> str[i];  //读入和输出整个字符串用cin 和 cout 
	sort(str, str + n, cmp);
	
	string ans;
	for(int i = 0; i < n; i++) ans += str[i];
	while(ans.size() != 0 && ans[0] == '0') ans.erase(ans.begin());//去除前导零 
	if(ans.size() == 0) printf("0"); //去除前导零后为空
	else cout << ans;
	return 0; 
}
