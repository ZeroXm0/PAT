#include <cstdio>
#include <map>
using namespace std;
const int inf = 0x3fffffff;
const int maxn = 1010;
int deep = 0, cnt[maxn];
struct Node{
	int data, level;
	Node *left, *right;
};
void create(Node* &root, int data) {
	if(root == NULL) {
		root = new Node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if(data <= root->data) {
		create(root->left, data);
	} else {
		create(root->right, data);
	}
}
void DFS(Node *root, int lever) {
	if(root == NULL) {
		if(lever > deep) {
			deep = lever;
		}
		return;
	}
	root->level = lever++;
	cnt[lever]++;
	DFS(root->left, lever); 
	DFS(root->right, lever);
}
int main() {
	int n, v;
	scanf("%d", &n);
	Node* root = NULL;
	for(int i = 0; i < n; i++) {
		scanf("%d", &v);
		create(root, v);
	}
	DFS(root, 0);
	printf("%d + %d = %d\n", cnt[deep], cnt[deep - 1], cnt[deep] + cnt[deep - 1]) ;
	return 0;
}
