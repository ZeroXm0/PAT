#include <cstdio>
const int maxn = 50010;
int pre[maxn], in[maxn];
struct node{
	int data;
	node *lchild, *rchild;
};
node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) return NULL;
	node *root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL; k < inR; k++) {
		if(pre[preL] == in[k]) break;
	}
	int numleft = k - inL;
	root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
	root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
	return root;
}
int ans = 0;
void printPost(node *root) {
	if(root->lchild != NULL) printPost(root->lchild);
	if(root->rchild != NULL) printPost(root->rchild);
	if(ans == 0){
		printf("%d\n", root->data);
		ans++; 
	} else {
		return;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node *root = create(0, n - 1, 0, n - 1);
	printPost(root);
	return 0;
}
