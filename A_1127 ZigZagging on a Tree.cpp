#include <cstdio>
#include <queue>
#include <vector> 
using namespace std; 
const int maxn = 31;
int post[maxn], in[maxn], num[maxn], n;
struct node{
	int v, l;
	node *lchild, *rchild;
};
vector<node *> v;
node* create(int l, int postL, int postR, int inL, int inR) {
	if(postL > postR) {
		return NULL;
	}
	node *root = new node;
	root->v = post[postR];
	root->l = l;
	int i;
	for(i = inL; i <= inR; i++) {
		if(in[i] == post[postR]) break;
	}
	int numleft = i - inL;
	root->lchild = create(l + 1, postL, postL + numleft - 1, inL, i - 1);
	root->rchild = create(l + 1, postL + numleft, postR - 1, i + 1, inR); 
	return root;
} 
void print(node *root) {
	queue<node *> q;
	q.push(root);
	int cnt = 0;
	while(q.size()) {
		node *top = q.front();
		q.pop();
		num[top->l]++;
		v.push_back(top);
		if(top->lchild != NULL) q.push(top->lchild);
		if(top->rchild != NULL) q.push(top->rchild);
	}
	int i = 0;
	while(i < v.size()) {
		int lever = v[i]->l;
		if(lever == 1 || lever %  2 == 0) {
			printf("%d", v[i]->v);
			if(++cnt != n) printf(" ");
			i++;
		} else {
			int k = i + num[lever] - 1;
			for(k; k >= i; k--) {
				printf("%d", v[k]->v);
				if(++cnt != n) printf(" ");
			}
			i = i + num[lever];
		}
	}
	printf("\n");
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	node *root = create(1, 0, n - 1, 0, n - 1);
	print(root);
	return 0;
}
