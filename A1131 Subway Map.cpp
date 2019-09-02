#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 10010;
int G[maxn][maxn];			//记录站点a->b的路线 
int n, m, k, start, End, minCnt, minStop;
bool vis[maxn];
vector<int> temp, path;
vector<vector<int> > v(maxn);
int getStop(vector<int> q) {			//计算中转站 
	int preline = G[q[0]][q[1]];
	int stopCnt = 0;
	for(int i = 2; i < q.size(); i++) {
		if(G[q[i - 1]][q[i]] != preline) {
			stopCnt++;
		}
		preline = G[q[i - 1]][q[i]];
	}
	return stopCnt;
}
void DFS(int start, int cnt) {			//计算路线，cnt计算站数，每次向下一个+1 ，图的遍历 
	if(start == End) {
		if(cnt < minCnt || (cnt == minCnt && getStop(temp) < minStop)) {
			minCnt = cnt;
			minStop = getStop(temp);
			path = temp;
		}
		return;
	} 
	for(int i = 0; i < v[start].size(); i++) {
		int id = v[start][i];
		if(vis[id] == false) {
			vis[id] = true;
			temp.push_back(id); 
			DFS(id, cnt + 1);
			vis[id] = false;
			temp.pop_back();
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int pre, next;
		scanf("%d%d", &m, &pre);
		for(int j = 1; j < m; j++) {
			scanf("%d", &next);
			G[pre][next] = G[next][pre] = i;
			v[pre].push_back(next);
			v[next].push_back(pre);
			pre = next;
		}
	}
	scanf("%d", &k);
	while(k--) {
		temp.clear(), path.clear();
		minCnt = 99999, minStop = 99999;
		scanf("%d%d", &start, &End);
		vis[start] = true;
		temp.push_back(start);
		DFS(start, 0);
		vis[start] = false;
		printf("%d\n", minCnt);
		int line = G[path[0]][path[1]];
		printf("Take Line#%d from %04d to ", line, start);
		for(int i = 2; i < path.size(); i++) {
			if(G[path[i - 1]][path[i]] != line) {
				printf("%04d.\n", path[i - 1]);
				line = G[path[i - 1]][path[i]];
				printf("Take Line#%d from %04d to ", line, path[i - 1]);
			}
		}
		printf("%04d.\n", End);
	}
	return 0;
}
