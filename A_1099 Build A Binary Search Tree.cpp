#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
bool flag[maxn] = {false};
int n, num[maxn];
struct node{
	int data, lchild, rchild;
}Node[maxn];
int index = 0;
void inOrder(int k) {
	if(k == -1) return;
	inOrder(Node[k].lchild);
	Node[k].data = num[index++];
	inOrder(Node[k].rchild);
}
void printRes(int k) {
	queue<int> q;
	q.push(k);
	int ans = 0;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d", Node[front].data);
		if(++ans < n) printf(" ");
		else printf("\n");
		if(Node[front].lchild != -1) q.push(Node[front].lchild);
		if(Node[front].rchild != -1) q.push(Node[front].rchild);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		Node[i].lchild = left;
		Node[i].rchild = right;
	}
		for(int i = 0; i < n; i++) scanf("%d", &num[i]);
		sort(num, num + n);
		inOrder(0);
		printRes(0);
		return 0;
}

