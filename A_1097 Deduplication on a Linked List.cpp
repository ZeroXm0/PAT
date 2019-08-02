#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool flag[maxn] = {false};		//记录绝对值是否已存在 
struct Node{
	int add, data, next;
	int order;				//表示原链表中次序， maxn为无效值
	bool flag;
	Node() {
		order = maxn;
		flag = false;			//false 表示不在新链表中 
	} 
}node[maxn];
bool cmp(Node a, Node b) {
	if(a.flag != b.flag) return a.flag > b.flag;		//不在数列中的放后面 
	else return a.order < b.order;						//不论在不在数列中，相同flag状态都是按次序排序 
} 
int main() {
	int first, n;
	scanf("%d%d", &first, &n);
	while(n--) {
		int add;
		scanf("%d", &add);
		node[add].add = add;
		scanf("%d %d", &node[add].data, &node[add].next);
	}
	int p = first, r = 0;
	while(p != -1) {
		node[p].order = ++r;
		int data = abs(node[p].data);
		if(flag[data] == false){
			node[p].flag = true;
			flag[data] = true;
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	for(int i = 0; i < r; i++){
		printf("%05d %d ", node[i].add, node[i].data);
		if(i == r - 1 || (node[i].flag != node[i + 1].flag) ) printf("-1\n");
		else printf("%05d\n", node[i + 1].add);
	}
	return 0;
}
