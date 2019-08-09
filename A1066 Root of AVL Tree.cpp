#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 25;
struct node{
	int v, height;
	node *lchild, *rchild;
}; 
node* newNode(int v) {
	node* root = new node;
	root->v = v;
	root->height = 1;
	root->lchild = root->rchild = NULL;
	return root;
}
int getHeight(node* root) {
	if(root == NULL) return 0;
	else return root->height;
}
void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getFac(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void turnL(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void turnR(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int v) {
	if(root == NULL) {
		root = newNode(v);
		return;
	}
	if(v < root->v){
		insert(root->lchild, v);
		updateHeight(root);
		if(getFac(root) == 2) {
			if(getFac(root->lchild) == 1) turnR(root);
			else if(getFac(root->lchild) == -1) {
				turnL(root->lchild);
				turnR(root);
			}
		}	
	} else {
		insert(root->rchild, v);
		updateHeight(root);
		if(getFac(root) == -2) {
			if(getFac(root->rchild) == -1) turnL(root);
			else if(getFac(root->rchild) == 1) {
				turnR(root->rchild);
				turnL(root);
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		insert(root, num);
	}
	printf("%d", root->v);
	return 0;
}
