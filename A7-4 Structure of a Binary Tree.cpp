#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 31;
int post[maxn], in[maxn], deep[maxn];
int n, m;
struct node{
	int v;
	node *lchild, *rchild, *parent;
};
map<int, node*> mp;
bool isfull = true;
node* create(int postL, int postR, int inL, int inR, int deepest) {
	if(postL > postR) return NULL;
	node *root = new node;
	root->v = post[postR];
	deep[root->v] = deepest;
	int k;
	for(k = inL; k <= inR; k++) {
		if(post[postR] == in[k]) break;
	}
	int leftNum = k - inL;
	root->lchild = create(postL, postL + leftNum - 1, inL, k - 1, deepest + 1);
	root->rchild = create(postL + leftNum, postR - 1, k + 1, inR, deepest + 1);
	if(root->lchild) root->lchild->parent = root;
	if(root->rchild) root->rchild->parent = root;
	if((!root->lchild && root->rchild) || (!root->rchild && root->lchild)) isfull = false;
	mp[root->v] = root;
	return root;
}
void judge(node *root, string s) {
	if(s.find("root") != string::npos) {
		int a;
		sscanf(s.c_str(), "%d is the root", &a);
		root->v == a ? printf("Yes\n") : printf("No\n");
		return;
	}
	if(s.find("siblings") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
		node *l = mp[a], *r = mp[b];
		l->parent == r->parent ? printf("Yes\n") : printf("No\n");
		return; 
	}
	if(s.find("parent") != string::npos) {
		int a, b;
		sscanf(s.c_str(),"%d is the parent of %d", &a, &b);
		node *l = mp[a], *r = mp[b];
		r->parent == l ? printf("Yes\n") : printf("No\n");
		return; 
	}
	if(s.find("left") != string::npos) {
		int a, b;
		sscanf(s.c_str(),"%d is the left child of %d", &a, &b);
		node *l = mp[a], *r = mp[b];
		r->lchild == l ? printf("Yes\n") : printf("No\n");
		return; 
	}
	if(s.find("right") != string::npos) {
		int a, b;
		sscanf(s.c_str(),"%d is the right child of %d", &a, &b);
		node *l = mp[a], *r = mp[b];
		r->rchild == l ? printf("Yes\n") : printf("No\n");
		return; 
	}
	if(s.find("level") != string::npos) {
		int a, b;
		sscanf(s.c_str(),"%d and %d are on the same level", &a, &b);
		deep[a] == deep[b] ? printf("Yes\n") : printf("No\n");
		return;
	} 
	if(s.find("full") != string::npos) {
		isfull ?  printf("Yes\n") : printf("No\n");
		return;
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
	node *root = create(0, n - 1, 0, n - 1, 1);
	scanf("%d", &m);
	getchar();			//ÎüÊÕ»»ÐÐ·û 
	while(m--) {
		string str;
		getline(cin, str);
		judge(root, str);
	}
}
