#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int add, data, next;
	int order;
	Node() {
		order = maxn;			//order表次序， maxn 表示无效值 
	}
}node[maxn];
bool cmp1(Node a, Node b) {
	return a.order < b.order;
}
bool cmp2(Node a, Node b) {
	return a.order > b.order;
}
int main() {
	int first, n, k;
	scanf("%d%d%d", &first, &n, &k);
	while(n--) {
		int add;
		scanf("%d", &add);
		node[add].add = add;
		scanf("%d %d", &node[add].data, &node[add].next); 
	} 
	int p = first, order = 0;
	while(p != -1) {
		node[p].order = ++order;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp1);
	int begin = 0, count = order / k;
	for(begin; begin < count * k; begin += k) {
		sort(node + begin, node + begin + k, cmp2);
	}
	for(int i = 0; i < order; i++) {
		printf("%05d %d ", node[i].add, node[i].data);
		if(i != order - 1) printf("%05d\n", node[i + 1].add);
		else printf("-1\n");
	}
	return 0;
}
