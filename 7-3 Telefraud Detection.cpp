#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1010;
int k, n, m;
int duration[maxn][maxn]; 			//记录ab间通话分钟数
bool vis[maxn];					//记录嫌疑人是否已加入 
int father[maxn];
vector<int> sus;				//记录嫌疑人 
map<int, vector<int> > res;
int find(int v) {
	int x = v;
	while(v != father[v]) {
		v = father[v];
	}
	while(x != father[x]) {
		father[x] = v;
		x = father[x];
	}
	return v;
}
void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa != fb) {
		fa < fb ? father[fb] = fa : father[fa] = fb;
	}
}
int main() {
	scanf("%d%d%d", &k, &n, &m);
	while(m--) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		duration[a][b] += d;
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) father[i] = i; 
	for(int i = 1; i <= n; i++) {
		int caller = 0, reciver = 0;
		for(int j = 1; j <= n; j++) {
			if(duration[i][j] > 0 && duration[i][j] <= 5) {
				caller++;
				if(duration[j][i] > 0) reciver++;
			}
		}
		if(caller > k && reciver * 5 <= caller) {
			bool flag = true;
			for(int j = 0;  j < sus.size(); j++) {
				if(duration[sus[j]][i] && duration[i][sus[j]]) {	
					Union(sus[j], i);				//此处不能单纯判断是否与前某个通话来直接合并，因为 两个有共同通话也是一个集合，所以用并查集，6分测试点 
				}
			}
			sus.push_back(i);
		}
	}
	if(sus.empty()) printf("None\n");
	else {
		for(int i = 0; i < sus.size(); i++) {			//	本就是从小到大循环的，不用再排序 
			res[find(sus[i])].push_back(sus[i]);
		}
		for(int i = 0; i < res.size(); i++) {
			if(res[i].size()) {
				for(int j = 0; j < res[i].size(); j++) {
					if(j != 0) printf(" ");
					printf("%d", res[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
} 
