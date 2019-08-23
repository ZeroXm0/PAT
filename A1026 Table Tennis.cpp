#include <cstdio>
#include <vector>
#include <cmath> 
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxc = 110;
struct Player{
	int arriveTime, startTime, trainTime;
	bool isVIP;
} newPlayer;
struct table{
	int num, leaveTime; 
	bool isVIP;
}tab[maxc];
int getTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
vector<Player> player;
int nextVIP(int VIP) {
	VIP++;
	while(VIP < player.size() && player[VIP].isVIP == 0) VIP++;
	return VIP; 
}
void allotTable(int play, int table) {
	if(player[play].arriveTime < tab[table].leaveTime) {
		player[play].startTime = tab[table].leaveTime;
	} else {
		player[play].startTime = player[play].arriveTime;
	}
	tab[table].leaveTime = player[play].startTime + player[play].trainTime;
	tab[table].num++;
}
bool cmpA(Player a, Player b) {
	return a.arriveTime < b.arriveTime;
}
bool cmpS(Player a, Player b) {
	return a.startTime < b.startTime;
}
int main() {
	int n;
	scanf("%d", &n);
	int stTime = getTime(8, 0, 0);
	int endTime = getTime(21, 0, 0);
	for(int i = 0 ; i < n; i++) {
		int h, m, s, p, tag;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &tag);
		if(getTime(h, m, s) >= endTime) continue;
		int train = p <= 120 ? p * 60 : 7200;
		newPlayer.arriveTime = getTime(h, m, s);
		newPlayer.startTime = endTime;
		newPlayer.trainTime = train;
		newPlayer.isVIP = tag;
		player.push_back(newPlayer);
	}
	int k, m;
	scanf("%d%d", &k, &m);
	for(int i = 1; i <= k; i++) {
		tab[i].isVIP = 0;
		tab[i].leaveTime = stTime;
		tab[i].num = 0;
	}
	for(int i = 0; i < m; i++) {
		int v; 
		scanf("%d", &v);
		tab[v].isVIP = 1;
	}
	sort(player.begin(), player.end(), cmpA);
	int i = 0, VIPi = -1;
	VIPi = nextVIP(VIPi);
	while(i < player.size()) {
		int idx = -1, minEnd = 0x3fffffff;
		for(int j = 1; j <= k; j++) {
			if(tab[j].leaveTime < minEnd) {
				idx = j;
				minEnd = tab[j].leaveTime;
			}
		}
		if(tab[idx].leaveTime >= endTime)	break;
		if(player[i].isVIP == 1 && i < VIPi) {
			i++;
			continue;
		}
		if(tab[idx].isVIP == 1) {
			if(player[i].isVIP == 1) {
				allotTable(i, idx);
				if(VIPi == i) VIPi = nextVIP(VIPi);
				i++;
			} else {
				if(VIPi < player.size() && player[VIPi].arriveTime <= tab[idx].leaveTime) {
				//这里要注意，首先要又vip，并且要早于空闲时间到达，注意点就是VIPi ！= i，i不变，变化的是VIPi 
					allotTable(VIPi, idx);
					VIPi = nextVIP(VIPi);	
				} else {
					allotTable(i, idx);
					i++;
				}
			}
		} else {
			if(player[i].isVIP == 0) {
				allotTable(i, idx);
				i++;
			} else {
				int VIPidx = -1, minVIPEnd = 0x3fffffff;
				for(int j = 1; j <= k; j++) {
					if(tab[j].isVIP == 1 && tab[j].leaveTime < minVIPEnd) {
						VIPidx = j;
						minVIPEnd = tab[j].leaveTime;
					}
				}
				if(VIPidx != -1 && player[i].arriveTime >= tab[VIPidx].leaveTime) {
					allotTable(i, VIPidx);
					if(VIPi == i) VIPi = nextVIP(VIPi);	
					i++;
				} else {
					allotTable(i, idx);
					if(VIPi == i) VIPi = nextVIP(VIPi);	
					i++;
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmpS);
	for(i = 0; i < player.size() && player[i].startTime < endTime; i++) {
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for(i = 1; i <= k; i++) {
		printf("%d", tab[i].num);
		if(i < k) printf(" ");
	}
	return 0;
}
