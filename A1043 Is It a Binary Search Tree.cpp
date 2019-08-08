#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1005;
struct node{
	int data;
	node* lchild;
	node* rchild;
}Node[maxn]; 
vector<int> ori, pre, preM, post, postM;
bool flag[maxn] = {false};
void insert(node* &root, int data) {			//注意传入节点带指针，才能改变各个节点 
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data)	insert(root->lchild, data);
	else insert(root->rchild, data);
}
void preOrder(node* root) {
	if(root == NULL)	return;
	pre.push_back(root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}
void premirrOrder(node* root) {
	if(root == NULL)	return;
	preM.push_back(root->data);
	premirrOrder(root->rchild);
	premirrOrder(root->lchild);
}
void postOrder(node* root) {
	if(root == NULL)	return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}
void postmirrOrder(node* root) {
	if(root == NULL)	return;
	postmirrOrder(root->rchild);
	postmirrOrder(root->lchild);
	postM.push_back(root->data);
}
int main() {
	int n;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		ori.push_back(data);
		insert(root, data);
	}
	preOrder(root);
	premirrOrder(root);
	postOrder(root);
	postmirrOrder(root);
	if(ori == pre) {
		printf("YES\n");
		for(int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if(i != post.size() - 1) printf(" ");
			else printf("\n");
		}
	} else if(ori == preM) {
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++) {
			printf("%d", postM[i]);
			if(i != postM.size() - 1) printf(" ");
			else printf("\n");
		}
	} else {
		printf("NO\n");
	} 
	return 0;
}
