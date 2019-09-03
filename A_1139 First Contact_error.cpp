#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;
set<int> v[maxn];
int n, m, k;
map<int, int> list;			//记录id的下标 
struct node{
	int c, d;
};
bool judge(int a, int b) {
	if(a >= 0 && b >= 0) return true;
	if(a < 0 && b < 0) return true;
	return false;
}
bool cmp(node a, node b) {
	if(a.c != b.c) return a.c < b.c;
	return a.d < b.d; 
}
int main() {
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for(int i = 1; i <= m; i++) {
		int f1, f2;
		scanf("%d%d", &f1, &f2);
		if(list[f1] != 0) {
			v[list[f1]].insert(f2); 
		} else {
			v[cnt].insert(f2);
			list[f1] = cnt++;
		}
		if(list[f2] != 0) {
			v[list[f2]].insert(f1); 
		} else {
			v[cnt].insert(f1);
			list[f2] = cnt++;
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		vector<node> res;
		int first, second;
		scanf("%d%d", &first, &second);
		int ans = 0;
		for(set<int>::iterator j = v[list[first]].begin(); j != v[list[first]].end(); j++) {
			int c = *j;
			if(c != second && judge(first, c)) {
				for(set<int>::iterator num = v[list[c]].begin(); num != v[list[c]].end(); num++) {
					int d = *num;
					if(d != second && judge(second, d) && v[list[second]].find(d) != v[list[second]].end()) {
						ans++;
						res.push_back(node{abs(c), abs(d)});
					}
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
