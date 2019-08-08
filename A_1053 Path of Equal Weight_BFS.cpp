#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
struct node{
	int weight;
	vector<int> child;
}Node[maxn]; 
int n, m, s;
int theW = 0, num = 0;
vector<vector<int> > v;
bool cmp(vector<int> a, vector<int> b) {
	for(int i = 0; i < a.size() && i < b.size(); i++) {
		if(Node[a[i]].weight != Node[b[i]].weight)	return Node[a[i]].weight > Node[b[i]].weight;
	}
	return false;		//	必须有返回值，处理两条路径完全相同的情况，否则最后一个判断点段错误，建议采用DFS中输入时就对子节点排序的做法更为简单 
}
void BFS(int i, vector<int> q, int theW) {
	q.push_back(i);
	theW += Node[i].weight;
	if(theW > s)	return;
	if(Node[i].child.size() == 0) {
		if(theW == s){
			v.push_back(q);
		}
	} else {
		for(int j = 0; j < Node[i].child.size(); j++) {
			BFS(Node[i].child[j], q, theW);
		}
	}
} 

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &Node[i].weight);
	}
	for(int i = 0; i < m; i++) {
		int id, num;
		scanf("%d%d", &id, &num);
		while(num--) {
			int child;
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
	}
	vector<int> list;
	BFS(0, list, 0);
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			printf("%d", Node[v[i][j]].weight);
			if(j != v[i].size() - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
