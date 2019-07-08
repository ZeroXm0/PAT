#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Car{
	char id[10];
	int time;//记录的时刻 
	char status[4];
}all[10010], valid[10010];
int num = 0;//记录有效记录的条数 
map<string, int> partTime;

int timeToInt(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
bool cmp(Car a, Car b) {
	if(strcmp(a.id,b.id)) return strcmp(a.id, b.id) < 0;
	else return a.time < b.time;
}
bool cmpTime(Car a,Car b) {
	return a.time < b.time;
}


int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int hh, mm, ss;
		scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
		all[i].time = timeToInt(hh, mm, ss);
	}
	
	sort(all, all + n, cmp);
	int maxTime = -1;
	for(int i = 0; i < n - 1; i++) {
		//同一车且先进后出 
		if(!strcmp(all[i].id, all[i + 1].id) &&
			!strcmp(all[i].status, "in") &&
			!strcmp(all[i + 1].status,"out")) {
				valid[num++] = all[i];
				valid[num++] = all[i + 1];
				int inTime = all[i + 1].time - all[i].time;
				if(partTime.count(all[i].id) == 0) {
					partTime[all[i].id];//map还无要先设，初始时间为0 
				}
				partTime[all[i].id] += inTime;
				maxTime = max(maxTime, partTime[all[i].id]);
			}
	}
	sort(valid, valid + num, cmpTime);//把有效的按时间排序 
	int now = 0, numCar = 0;//当前时间及停留车辆 
	for(int i = 0; i < m; i++){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = timeToInt(hh, mm, ss);//需查询的时间
		while(now < num && valid[now].time <= time) {
			if(!strcmp(valid[now].status, "in")) numCar++;//进入车辆加1，出减一 
			else numCar--;
			now++;
		} 
		printf("%d\n",numCar);
	}
	map<string, int>::iterator it;//遍历所有车牌号
	for(it = partTime.begin(); it != partTime.end(); it++) {
		if(it -> second == maxTime) {//输出车牌号 
			printf("%s ", it -> first.c_str());
		}
	} 
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}
