#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n, isComplete = 1;
struct Node {
	int v, height;
	Node *lchild, *rchild;
}; 
Node* newNode(int v) {
	Node *node = new Node;
	node->v = v;
	node->height = 1;
	node->lchild = node->rchild = NULL;
	return node; 
}
int getHeight(Node* root) {
	if(root == NULL) return 0;
	return root->height;
}
void updateHeight(Node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBanlance(Node *root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void R(Node* &root) {
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void L(Node* &root) {
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(Node* &root, int v) {
	if(root == NULL) {
		root = newNode(v);
		return;
	}
	if(v < root->v) {
		insert(root->lchild, v);
		updateHeight(root);
		if(getBanlance(root) == 2) {
			if(getBanlance(root->lchild) == 1) {
				R(root);
			}  else if(getBanlance(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	} else {
		insert(root->rchild, v);
		updateHeight(root);
		if(getBanlance(root) == -2) {
			if(getBanlance(root->rchild) == -1) {
				L(root);
			} else if(getBanlance(root->rchild) == 1) {
				R(root->rchild);		//RL型，注意先转子树 ，转变为RR型 
				L(root);
			}
		}
	}
}
int ans = 0, after = 0;
void leverPrint(Node* root) {
	queue<Node *> q;
	q.push(root);
	while(q.size()) {
		Node* temp = q.front();
		q.pop();
		printf("%d", temp->v);
		ans++;
		if(ans < n) printf(" ");
		else printf("\n");
		if(temp->lchild != NULL) {
			if(after) isComplete = 0;
			q.push(temp->lchild);
		} else {
			after = 1;
		}
		if(temp->rchild != NULL) {
			if(after) isComplete = 0;
			q.push(temp->rchild);
		} else {
			after = 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	Node* root = NULL;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		insert(root, num);
	}
	leverPrint(root);
	if(isComplete) printf("YES\n");
	else printf("NO\n");
	return 0; 
}
