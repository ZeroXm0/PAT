#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;
vector<int> Node[maxn];
bool flag[maxn] = {false};
int n, sum = 0;
double p, r, ans = INF;
void BFS(int i, int level) {
	if(Node[i].size() == 0) {
		double price = p * pow(1 + r, level);
		if(price < ans) {
			ans = price;
			sum = 1;
		} else if(price == ans) {
			sum++;
		}
		return;
	} else {
		for(int j = 0; j < Node[i].size(); j++) {
			BFS(Node[i][j], level + 1);
		}
	}
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if(num != 0) {
			for(int j = 0; j < num; j++) {
				int cnt;
				scanf("%d", &cnt);
				Node[i].push_back(cnt);
			}	
		}
	}
	int k;
	for(k = 0; k < n; k++) {
		if(flag[k] == false)	break;
	}
	BFS(k, 0);
	printf("%.4f %d\n", ans, sum);
	return 0;
}
