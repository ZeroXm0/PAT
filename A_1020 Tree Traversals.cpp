#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 31;
int n, post[maxn], in[maxn];
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};
Node* create(int postl, int postr, int intl, int intr) {
	if(postl > postr){			//相等时也要加入子树 
		return NULL;
	}
	Node* root = new Node;
	root->data = post[postr];
	int k;
	for(k = intl; k <= intr; k++) {
		if(in[k] == post[postr])	break;
	}
	int numleft = k - intl; 
	root->lchild = create(postl, postl + numleft - 1, intl, k - 1);
	root->rchild = create(postl + numleft, postr - 1, k + 1, intr);
	return root;
}
int num = 0;
void level(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* top = q.front();
		q.pop();
		printf("%d", top->data);
		num++;
		if(num < n) printf(" ");
		if(top->lchild != NULL) q.push(top->lchild);
		if(top->rchild != NULL) q.push(top->rchild);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);	
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	Node* root = create(0, n - 1, 0, n - 1);
	level(root);
	return 0;
}
