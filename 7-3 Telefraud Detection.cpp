#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1010;
int k, n, m;
int duration[maxn][maxn]; 			//记录ab间通话分钟数
int peo[maxn];					//记录嫌疑人所属组 
vector<int> sus;				//记录嫌疑人 
map<int, vector<int> > res;
int main() {
	scanf("%d%d%d", &k, &n, &m);
	while(m--) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		duration[a][b] += d;
	}
	int ans = 1;
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
					peo[i] = peo[sus[j]];
					res[peo[i]].push_back(i);
					flag = false;
					break;
				}
			}
			if(flag) {
				peo[i] = ans;
				res[ans++].push_back(i);
			}
			sus.push_back(i);
		}
	}
	if(sus.empty()) printf("None\n");
	else {
		for(int i = 1; i < ans; i++) {			//	本就是从小到大循环的，不用再排序 
			for(int j = 0; j < res[i].size(); j++) {
				if(j != 0) printf(" ");
				printf("%d", res[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
