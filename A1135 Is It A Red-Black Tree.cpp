#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
struct Node{
	int v;
	Node *lchild, *rchild;
}; 
void create(Node* &root, int v) {
	if(root == NULL) {
		root = new Node;
		root->v = v;
		root->lchild = root->rchild = NULL;
		return; 
	}
	if(abs(v) <= abs(root->v)) {
		create(root->lchild, v);
	} else {
		create(root->rchild, v);
	}
}
bool judge1(Node *root) {
	if(root == NULL) return true;
	if(root->v < 0) {
		if(root->lchild != NULL && root->lchild->v < 0) return false;
		if(root->rchild != NULL && root->rchild->v < 0) return false;
	}
	return judge1(root->lchild) && judge1(root->rchild);
}
int getNum(Node *root) {
	if(root == NULL) return 0;
	int l = getNum(root->lchild);
	int r = getNum(root->rchild);
	return root->v > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(Node *root) {
	if(root == NULL) return true;
	int l = getNum(root->lchild);
	int r = getNum(root->rchild);
	if(l != r) return false;
	return judge2(root->lchild) && judge2(root->rchild);
}
int main() {
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        Node *root = NULL;
        for(int j = 0; j < n; j++) {
        	int v;
        	scanf("%d", &v);
        	create(root, v);
		}
		if(root->v >= 0 && judge1(root) && judge2(root)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
    }
    return 0;
}
