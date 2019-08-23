#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxc = 110;
const int INF = 0x3fffffff; 
int endTime[maxc];
struct Custom{
	int arrive, pass;
}temp[maxn];
bool cmp(Custom a, Custom b) {
	return a.arrive < b.arrive;
}
int toS(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
int main() {
	int n, k, totalWait = 0;
	scanf("%d%d", &n, &k);
	int num = 0;
	for(int i = 0; i < n; i++) {
		int hh, mm, ss, pass;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &pass);
		int time = toS(hh, mm, ss);
		if(time <= toS(17,0,0)) {
			temp[num].arrive = time;
			temp[num++].pass = pass <= 60 ? pass * 60 : 3600;
		}
	}
	for(int i = 0; i < k; i++) endTime[i] = toS(8, 0, 0);			//note：初始化每个窗口结束时间为8点 
	sort(temp, temp + num, cmp);
	for(int i = 0; i < num; i++) {
		int idx = -1, minEnd = INF;
		for(int j = 0; j < k; j++) {
			if(endTime[j] < minEnd) {
				minEnd = endTime[j];
				idx = j;
			}
		}
		if(minEnd <= temp[i].arrive) {
			endTime[idx] = temp[i].arrive + temp[i].pass; 
		} else {
			totalWait += (minEnd - temp[i].arrive);
			endTime[idx] += temp[i].pass;
		}
	}
	if(num == 0) printf("0.0\n");
	else printf("%.1f\n", totalWait / 60.0 / num);
	return 0;
}
