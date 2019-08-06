#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 50;
int n, pre[maxn], in[maxn], pnum = 0, inum = 0;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int prel, int prer, int inl, int inr) {
	if(prel > prer)	return NULL;
	node* root = new node;
	root->data = pre[prel];
	int k;
	for(k = inl; k <= inr; k++) {
		if(in[k] == pre[prel]) break;
	} 
	int numleft = k - inl;
	root->lchild = create(prel + 1, prel + numleft, inl, k - 1);
	root->rchild = create(prel + numleft + 1, prer, k + 1, inr);
	return root;
} 
int num = 0;
void DFS(node* root) {
	if(root->lchild != NULL)	DFS(root->lchild);
	if(root->rchild != NULL)	DFS(root->rchild);
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
}
int main() {
	scanf("%d", &n);
	getchar();
	char str[5];
	stack<int> s;
	for(int i = 0; i < 2 * n; i++) {
		scanf("%s", str);			//¾¡Á¿±ðÓÃcin 
		if(strcmp(str, "Pop") == 0) {
			in[inum++] = s.top();
			s.pop(); 
		} else {
			scanf("%d", &pre[pnum++]);
			s.push(pre[pnum - 1]);
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	DFS(root);
	return 0;
} 
