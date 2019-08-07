#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
}Node[maxn];
int n, ans = 0, maxdepth = 0;
bool flag[maxn] = {false};
double p, r, price;
void BFS(int i, int level) {
	if(Node[i].child.size() == 0) {
		double nowprice = p * pow(1 + r, level);
		if(nowprice > price){
			ans = 1;
			price = nowprice;
		} else if(nowprice == price) {
			ans++;
		}
		return;
	} else {
		for(int j = 0; j < Node[i].child.size(); j++) {
			BFS(Node[i].child[j], level + 1);
		}
	}
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	price = p;
	r /= 100;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if(num != -1) {
			Node[num].child.push_back(i);
			flag[i] = true;
		}
	}
	int k;
	for(k = 0; k < n; k++) {
		if(flag[k] == false) break;
	}
	BFS(k, 0);
	printf("%.2f %d\n", price, ans);
}
