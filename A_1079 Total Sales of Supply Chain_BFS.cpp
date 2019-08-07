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
void BFS(int i) {			//此处用深度优先算法更简简洁 
	queue<int> q;
	Node[i].layer = 0;
	q.push(i);
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		int sum = Node[top].child.size();
		if(sum == 0) {
			
			ans += Node[top].num * pow(1 + r, Node[top].layer);
		} else {
			for(int j = 0; j < sum; j++) {
				int cnt = Node[top].child[j];
				Node[cnt].layer = Node[top].layer + 1;
				q.push(cnt);
			}
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
	BFS(k);
	printf("%.1f\n", p * ans);
	return 0;
}
