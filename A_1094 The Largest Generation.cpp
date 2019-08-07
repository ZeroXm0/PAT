#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 110;
int n, m, ans[maxn] = {0}, maxd = 1, depth = 1;
bool flag[maxn] = {false};
struct node{
	vector<int> child;
}Node[maxn];
void BFS(int i, int level) {
	if(Node[i].child.size() != 0) {
		for(int j = 0; j < Node[i].child.size(); j++) {
			ans[level + 1]++;
			BFS(Node[i].child[j], level + 1);
		}
		if(ans[level + 1] > maxd) {
			maxd = ans[level + 1];
			depth = level + 1;
		}
	} else {
		return;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int cnt, num;
		scanf("%d%d", &cnt, &num);
		for(int j = 0; j < num; j++) {
			int i;
			scanf("%d", &i);
			Node[cnt].child.push_back(i);
			flag[i] = true;
		}
	}
	int k;
	for(k = 1; k <= n; k++) {
		if(flag[k] == false)	break;
	}
	BFS(k,1);
	printf("%d %d\n",  maxd, depth);
	return 0;
}
