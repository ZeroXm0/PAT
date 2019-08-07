#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
	int num, layer;
}Node[maxn];
bool flag[maxn] = {false}; 
int n;
double p, r, ans = 0.0;
void DFS(int i, int level) {			//此处用深度优先算法
	if(Node[i].child.size() == 0) {
		ans += Node[i].num * pow(1 + r, level);
		return;
	} else {
		for(int j = 0; j < Node[i].child.size(); j++) {
			DFS(Node[i].child[j], level + 1);
		}
	}
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if(num == 0) {
			scanf("%d", &Node[i].num);
		} else {
			while(num--){
				int sum;
				scanf("%d", &sum);
				Node[i].child.push_back(sum);
				flag[sum] = true;
			}
		}
	}
	int k;
	for(k = 0; k < n; k++) {
		if(flag[k] == false) break;
	}
	DFS(k, 0);
	printf("%.1f\n", p * ans);
	return 0;
}
