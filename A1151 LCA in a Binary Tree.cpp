#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 10010;
int m, n, in[maxn], pre[maxn];
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
}; 
map<int, Node> tree;
Node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) return NULL;
	Node* root = new Node;
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) {
			break;
		}
	}
	int numleft = k - inL;
	root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
	root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
	return root;
}
Node* LCA(Node *T, int u, int v) {
	if(T == NULL) return NULL;
	if(T->data == u || T->data == v) return T;
	Node* l = LCA(T->lchild, u, v);
	Node* r = LCA(T->rchild, u, v);
	if(l != NULL && r != NULL) return T;
	return l == NULL? r : l;
}
bool findNum(int k) {
	for(int i = 0; i < n; i++) {
		if(in[i] == k) return true;
	}
	return false;
}
int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	Node* root = create(0, n - 1, 0, n - 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(findNum(u) == false && findNum(v) == false) {
			printf("ERROR: %d and %d are not found.\n", u, v);
		} else if(findNum(u) == false || findNum(v) == false) {
			printf("ERROR: %d is not found.\n", findNum(u) == false ? u : v);		//注意这里是is 
		} else {
			Node* T = LCA(root, u, v);
			if(T->data == u || T->data == v) {
				printf("%d is an ancestor of %d.\n", T->data == u ? u : v, T->data == u ? v : u);
			} else {
				printf("LCA of %d and %d is %d.\n", u, v, T->data);
			}
		}
	}
	return 0;
}
