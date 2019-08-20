#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, node[maxn];
vector<int> temp;
void showTree(int v) {
	int left = 2 * v, right = left + 1;
	if(left > n) {
		printf("%d", node[1]);
		for(int i = 0; i < temp.size(); i++) {
			printf(" %d", temp[i]);
		}
		printf("\n");
		return;
	}
	if(right <= n) {
		temp.push_back(node[right]);
		showTree(right);
		temp.pop_back();
	}
	if(left <= n) {
		temp.push_back(node[left]);
		showTree(left);
		temp.pop_back();	
	}
} 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &node[i]);
	}
	showTree(1);
	int flag = node[1] > node[2] ? 1 : 0;
	for(int i = 1; i <= n / 2; i++) {
		if(flag && (node[i] < node[i * 2] || ( i * 2 + 1 <= n && node[i] < node[i * 2 + 1])) ) {
			flag = -1;
			break;
		}
		if(!flag && (node[i] > node[i * 2] || ( i * 2 + 1 <= n && node[i] > node[i * 2 + 1])) ) {
			flag = -1;
			break;
		}
	}
	if(flag==-1)	printf("Not Heap\n");
	else printf(flag?"Max Heap\n":"Min Heap\n");
	return 0; 
} 
