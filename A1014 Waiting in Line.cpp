#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int ans[maxn], needTime[maxn];
struct Window{
	int endTime, popTime;
	queue<int> q;
}window[20];
int getTime(int hh, int mm) {
	return hh * 60 + mm;
}
int main() {
	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 0; i < k; i++) {
		scanf("%d", &needTime[i]);
	}
	for(int i = 0; i < n; i++){
		window[i].popTime = window[i].endTime = getTime(8, 0);
	}
	int idx = 0;
	for(int i = 0; i < min(n * m, k); i++) {
		window[idx % n].q.push(idx);
		window[idx % n].endTime += needTime[idx];
		if(idx < n) window[idx].popTime += needTime[idx];			//这里是否用"+" 皆可，不用加号就是这一队已办理结束的耗时，耗时最短即也是队首最早结束的 
		ans[idx] = window[idx % n].endTime;
		idx++;
	}
	for(; idx < k; idx++) {
		int index = -1, min = 0x3fffffff;
		for(int j = 0; j < n; j++) {
			if(window[j].popTime < min) {
				index = j;
				min = window[j].popTime; 
			}
		}
		Window& w = window[index];
		w.q.pop();
		w.q.push(idx);
		w.endTime += needTime[idx];
		w.popTime += needTime[w.q.front()];
		ans[idx] = w.endTime;
	}
	for(int i = 0; i < q; i++) {
		int query;
		scanf("%d", &query);				//注意我们是从0编号 
		if(ans[query - 1] - needTime[query - 1] >= getTime(17, 0)) printf("Sorry\n");
		else printf("%02d:%02d\n", ans[query - 1] / 60, ans[query - 1] % 60);
	}
	return 0;
}
