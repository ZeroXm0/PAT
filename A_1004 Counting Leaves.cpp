#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int n, m, ans[maxn], depth = 1;
bool flag[maxn] = {false};
void BFS(int i, int level) {
	if(Node[i].size() == 0) {
		ans[level]++;
		if(level > depth) depth = level;
		return;
	} else {
		for(int j = 0; j < Node[i].size(); j++) {
			BFS(Node[i][j], level + 1);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int id, num;
		scanf("%d%d", &id, &num);
		while(num--) {
			int child;
			scanf("%d", &child);
			Node[id].push_back(child);
			flag[child] = true;
		}
	}
	int k;
	for(k = 1; k <= n; k++) {
		if(flag[k] == false) break;
	}
	BFS(k, 1);
	for(int i = 1; i <= depth; i++) {
		printf("%d", ans[i]);
		if(i != depth) printf(" ");
		else printf("\n");
	}
	return 0;
}
