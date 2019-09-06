#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;
int tree[maxn];
int n;
vector<int> temp;
void showTree(int v) {			//深度优先算法，从右子树到左子树以此存储 
	int left = 2 * v, right = left + 1;
	if(left > n) {
		printf("%d", tree[1]);
		for(int i = 0; i < temp.size(); i++) {
			printf(" %d", temp[i]);
		}
		printf("\n");
		return;
	}
	if(right <= n) {
		temp.push_back(tree[right]);
		showTree(right);
		temp.pop_back();
	}
	if(left <= n) {
		temp.push_back(tree[left]);
		showTree(left);
		temp.pop_back();	
	}
} 
bool judge(int a[]) {
	int flag = a[1] > a[2] ? 1 : 0;
	for(int i = 1; i <= n / 2; i++) {
		if(flag && (a[i] < a[i * 2] || (i * 2 + 1 <= n && a[i] < a[i * 2 + 1]))) {
			flag = -1;
			break;
		}
		if(!flag && (a[i] > a[i * 2] || (i * 2 + 1 <= n && a[i] > a[i * 2 + 1]))) {
			flag = -1;
			break;
		}
	}
	if(flag == -1) printf("Not Heap\n");
	else printf(flag?"Max Heap\n":"Min Heap\n");
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tree[i]);
	}
	showTree(1);
	judge(tree);
	return 0;
}
