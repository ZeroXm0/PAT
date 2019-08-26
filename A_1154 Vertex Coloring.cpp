#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 10001;
const int Inf = 0x3fffffff;
struct node{
	int v1,v2;
};
int color[maxn];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	vector<node> vec(m);
	fill(color, color + maxn, -1);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &vec[i].v1, &vec[i].v2);
	}
	int k;
	scanf("%d", &k);
	for(int v = 0; v < k; v++) {
		set<int> ans;
		for(int j = 0; j < n; j++) {
			scanf("%d", &color[j]);
			ans.insert(color[j]);
		}
		bool flag = true;
		for(int i = 0; i < m; i++) {
			int v1,v2;
			v1 = vec[i].v1;
			v2 = vec[i].v2;
			printf("%d %d ", v1, v2);
			if(color[v1] == color[v2]) {
				flag = false;
				break;
			}
		}
		if(flag == false) printf("No\n");
		else {
			printf("%d-coloring\n", ans.size());
		}
	}
	return 0;
}
