#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
struct node{
	int weight;
	vector<int> child;
}Node[maxn]; 
int n, m, s, path[maxn];
bool cmp(int a, int b) {
	return Node[a].weight > Node[b].weight;
}
void DFS(int i,int numNode, int theW) {
	if(theW > s)	return;
	if(theW == s) {
		if(Node[i].child.size() != 0) return;
		for(int j = 0; j < numNode; j++) {
			printf("%d", Node[path[j]].weight);
			if(j != numNode - 1) printf(" ");
			else printf("\n");
		}
		return; 
	}
	for(int j = 0; j < Node[i].child.size(); j++) {
		int child = Node[i].child[j];
		path[numNode] = child;
		DFS(child, numNode + 1, theW + Node[child].weight);
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
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);		//按权重排序孩子节点，这样输入的顺序就会按权重排序 
	}
	path[0] = 0;
	DFS(0, 1, Node[0].weight);
	return 0;
}
