#include <cstdio>
#include <algorithm>
using namespace std;
struct station {
	double price, dis;
}sta[510];
double  cmax, d, davg;
int n;
bool cmp (station a, station b) {
	return a.dis < b.dis;
}

int main() {
	scanf("%lf %lf %lf %d", &cmax, &d, &davg,&n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sta[n].price = 0;
	sta[n].dis = d;//终点 
	sort(sta, sta + n,cmp);
	if(sta[0].dis != 0) printf("The maximum travel distance = 0.00\n");
	else {
		int now = 0;//当前所在加油站
		double cost = 0, nowtank = 0, max = cmax * davg;
		while(now < n) {
			int k = -1;	//最低油价的加油站编号
			double minprice = 1000000000;
			for(int i = now + 1; i <= n && sta[i].dis - sta[now].dis <= max; i++){//从下一个站点开始找，比现在站点价格低的站点或者能到达的剩余点中价格最低的点 
				if(sta[i].price < minprice) {
					minprice = sta[i].price;//已经找过的最便宜的站点 
					k = i;
					if(minprice < sta[now].price) break;//找到第一个比当前站点便宜的站点 
				} 
			} 
			if(k == -1) break;//满油状态下找不到加油站 
			double need = (sta[k].dis - sta[now].dis) / davg;//在当前站点加油到足够到达k的站点的油量
			if(minprice < sta[now].price) {//k 的价格低于当前，那只需加油到足够到k就可以了 
				if(nowtank < need) {
					cost += (need - nowtank) * sta[now].price;
					nowtank = 0; //到达k后油量为0 
				}else {
					nowtank -= need;
				} 
			} else {//k的油价高于当前 
				cost += (cmax - nowtank) * sta[now].price;
				nowtank = cmax - need;
			}
			now = k;
		}
		if(now == n) {
			printf("%.2f\n", cost);
		} else {
			printf("The maximum travel distance = %.2f\n", sta[now].dis + max);
		}
	}
	return 0;
}
