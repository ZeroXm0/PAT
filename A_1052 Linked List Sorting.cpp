#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int add, data, next;
	bool flag;
	Node() {
		flag = false;
	}
}node[maxn];
bool cmp(Node a, Node b) {
	if(a.flag == false || b.flag == false)	return a.flag > b.flag;			// true 在前 
	else return a.data < b.data;
}
int main() {
	int n, begin;
	scanf("%d%d", &n, &begin);
	while(n--) {
		int add;
		scanf("%d", &add);
		node[add].add = add;
		scanf("%d%d", &node[add].data, &node[add].next);
	}
	int p = begin, count = 0;
	while(p != -1){					//注意判断是否为链表内的数据 
		node[p].flag = true;
		p = node[p].next;
		count++;
	}
	if(count == 0) printf("0 -1\n");
	else {
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", count, node[0].add);
		for(int i = 0; i < count; i++) {
			printf("%05d %d ", node[i].add, node[i].data);
			if(i != count - 1) printf("%05d\n", node[i + 1].add);				//排序后next变为下一个的地址 ，最后一个数的next 为-1 
			else printf("-1\n");
		}
	}
	return 0;
}
