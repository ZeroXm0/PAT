#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
struct Station{
	double dis, price;
} sta[maxn];
bool cmp(Station a, Station b) {
	return a.dis < b.dis;
}
int main() {
	int cmax, d, davg, n;
	double minPrice, maxDis = 0;
	scanf("%d%d%d%d", &cmax, &d, &davg, &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sta[n].dis = d;
	sta[n].price = 0;
	sort(sta, sta + n, cmp);
	if(sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00\n");
	} else {
		double fullDis = cmax * davg, tank = 0;
		int now = 0;
		while(now < n) {
			int minP = 0x3fffffff;
			int idx = -1;	//最便宜的加油站 
			for(int i = now + 1; i <= n && sta[i].dis - sta[now].dis <= fullDis; i++) {
				if(sta[i].price < minP) {
					idx = i;
					minP = sta[i].price;
					if(minP < sta[now].price) break;
				}
			}
			if(idx == -1) {			//没有可到达的地点 
				maxDis = sta[now].dis + fullDis;
				break;
			}
			double need = (sta[idx].dis - sta[now].dis) / davg;
			if(minP < sta[now].price) {			//不用比较=, double型
				if(need > tank) { 
					minPrice += (need - tank) * sta[now].price;
					tank = 0; 
				} else {
					tank -= need;
				}
			} else {
				minPrice += (cmax - tank) * sta[now].price;
				tank = cmax - need;
			}
			now = idx;
		}
		if(now < n) {
			printf("The maximum travel distance = %.2f\n", maxDis);
		} else {
			printf("%.2f\n", minPrice);
		}
	} 
	
	return 0;
} 
