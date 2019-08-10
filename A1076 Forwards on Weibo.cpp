#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1010;
int n, l;
struct node{
	int id, layer;
};
vector<node> adj[maxn];
bool inq[maxn] = {false};
int BFS(int s, int l) {
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()) {
		node top = q.front();
		q.pop();
		int u = top.id;
		for(int i = 0; i < adj[u].size(); i++) {
			node next = adj[u][i];
			next.layer = top.layer + 1;
			if(inq[next.id] == false && next.layer <= l) {
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	} 
	return numForward;
}
int main() {
	int k;		//记录起始点 
	node user;
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++) {
		int num;
		user.id = i;
		scanf("%d", &num);
		for(int j = 0; j < num; j++) {
			int follow;
			scanf("%d", &follow);
			adj[follow].push_back(user); 
		}
	}
	int numq, s;
	scanf("%d", &numq);
	for(int i = 0; i < numq; i++) {
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);
		printf("%d\n", BFS(s, l));
	}
	return 0;
} 
