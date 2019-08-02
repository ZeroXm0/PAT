#include <cstdio>
#include <cstring>
const int maxn = 100010;
struct Node {
	char data;
	int next;
	bool flag;
	Node(){
		flag = false;
	}
}node[maxn]; 
int main() {
	int first, second, n;
	scanf("%d%d%d", &first, &second, &n);
	while(n--) {
		int add, next;
		char data;
		scanf("%d %c %d", &add, &data, &next);
		node[add].data = data;
		node[add].next = next;
	}
	int p = first;
	for(p; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for(p = second; p != -1; p = node[p].next) {
		if(node[p].flag == true) break;
	}
	if(p != -1) {
		printf("%05d\n", p);
	} else {
		printf("-1\n");
	}
	return 0;
}

