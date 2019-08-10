#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 2010;		//通话是双方所以最多有2000人 
map <int, string> intToStr;
map <string, int> strToInt;
map <string, int> gang;
int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, nump = 0;
bool vis[maxn] = {false};
int change(string str) {
	if(strToInt.find(str) != strToInt.end()) return strToInt[str];
	else {
		strToInt[str] = nump;
		intToStr[nump] = str;
		return nump++;
	}
}
void DFS(int nowVis, int& head, int& numMem, int& totalV) {
	numMem++;
	vis[nowVis] = true;
	if(weight[nowVis] > weight[head]) {
		head = nowVis;
	}
	for(int i = 0; i < nump; i++) {
		if(G[nowVis][i] > 0) {
			totalV += G[nowVis][i];
			G[nowVis][i] = G[i][nowVis] = 0;
			if(vis[i] == false) {
				DFS(i, head, numMem, totalV);
			}
		}
	}
}

void DFSTrave() {
	for(int i = 0; i < nump; i++) {
		if(vis[i] == false) {
			int head = i, numMem = 0, totalV = 0;
			DFS(i, head, numMem, totalV);
			if(numMem > 2 && totalV > k) {
				gang[intToStr[head]] = numMem;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	string str1, str2;
	int w;
	for(int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	DFSTrave();
	cout << gang.size() << endl;
	map<string, int>::iterator it;
	for(it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
