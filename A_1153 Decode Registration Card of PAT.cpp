#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int maxn = 10010;
const int maxc = 110;
int n, m;
struct node {
	string cardNum;
	int score;
} stu[maxn], temp;
bool cmp1(node a, node b) {
	if(a.score != b.score) return a.score > b.score;
	else return a.cardNum < b.cardNum;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		cin >> stu[i].cardNum >> stu[i].score;
	}
	for(int i = 1; i <= m; i++) {
		string term;
		int type, nt = 0, ns = 0;
		cin >> type >> term;
		cout << "Case " << i << ": " << type << " " << term << endl;
		vector<node> ans;
		if(type == 1) {
			for(int i = 0; i < n; i++) 
			 	if(stu[i].cardNum[0] == term[0]) ans.push_back(stu[i]);
		} else if(type == 2) {
			for(int i = 0; i < n; i++)
				if(stu[i].cardNum.substr(1, 3) == term) {
					nt++;
					ns += stu[i].score;
				}
			if(nt != 0) printf("%d %d\n", nt, ns);
		} else {
			map<string, int> cnt;
			for(int i = 0; i < n; i++)
				if(stu[i].cardNum.substr(4, 6) == term) {
					string cardNum = stu[i].cardNum.substr(1, 3);
					cnt[cardNum]++;
				}
			for(map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
				temp.cardNum = it->first;
				temp.score = it->second;
				ans.push_back(temp);
			}
		}
		sort(ans.begin(), ans.end(),cmp1);
        for (int j = 0; j < ans.size(); j++)
            printf("%s %d\n", ans[j].cardNum.c_str(), ans[j].score);
        if (((type == 1 || type == 3) && ans.size() == 0) || (type == 2 && nt == 0)) printf("NA\n");
	}
	return 0;
} 
