#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 20;
int n, flag[maxn] = {false};
struct node{
	int lchild, rchild;
}Node[maxn];
int num = 0;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		printf("%d", top);
		if(++num < n)	printf(" ");
		else printf("\n");
		if(Node[top].lchild != -1)	q.push(Node[top].lchild);
		if(Node[top].rchild != -1)	q.push(Node[top].rchild);
	}
} 
int cnt = 0;
void inorder(int begin) {
	if(begin == -1)	return;
	inorder(Node[begin].lchild);
	printf("%d", begin);
	if(++cnt < n)	printf(" ");
	else printf("\n");
	inorder(Node[begin].rchild);
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		getchar();
		char c1, c2;
		scanf("%c %c", &c1, &c2);
		if(c1 != '-') {
			Node[i].rchild = c1 - '0';
			flag[Node[i].rchild] = true;
		} else {
			Node[i].rchild = -1;
		}
		if(c2 != '-') {
			Node[i].lchild = c2 - '0';
			flag[Node[i].lchild] = true;
		} else {
			Node[i].lchild = -1;
		}
	}
	int i;
	for(i = 0; i < n; i++) {
		if(flag[i] == false) break;		//找出根节点 
	}
	BFS(i);
	inorder(i);
	return 0; 
}
