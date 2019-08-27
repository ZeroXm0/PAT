#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
const int maxn= 1010;
int n, m, k, origin[maxn], in[maxn];
set<int> list;
int main() {
	memset(origin, 0, sizeof(origin));
	scanf("%d%d", &n, &m);
	vector<vector<int> > ori(n + 1);
	for(int i = 0; i < m; i++) {
		int start, end;
		scanf("%d%d", &start, &end);
		ori[start].push_back(end);
		origin[end]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		for(int j = 1; j <= n; j++) {
			in[j] = origin[j];
		}
		for(int a = 0; a < n; a++) {
			int num;
			scanf("%d", &num);
			if(in[num] != 0) list.insert(i);
			for(int j = 0; j < ori[num].size(); j++) {
				in[ori[num][j]]--;
			}
		}
	}
	set<int>::iterator it = list.begin();
	printf("%d", *it);
	for(it++; it != list.end(); it++) {
		printf(" %d", *it);
	}
	return 0;
}
