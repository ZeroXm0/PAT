#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 200;
const int INF = 0x3fffffff;
int n, k, ansNum = 0, ansHappy = -1, avgHappy = -1, G[maxn][maxn], d[maxn], happen[maxn];
string start, rom = "ROM";
bool vis[maxn] = {false};
map<string, int> cityToId;
map<int, string> idToCity;
vector<int> pre[maxn];
vector<int> tempPath, path;
void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for(int j = 0; j < n; j++) {
			if(vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1)	return;
		vis[u] = true;
		for(int v = 0; v < n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(G[u][v] + d[u] < d[v]) {
					d[v] = G[u][v] + d[u];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(G[u][v] + d[u] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v) {
	tempPath.push_back(v);
	if(v == 0) {
		int happy = 0;
		ansNum++;
		for(int i = tempPath.size() - 2; i >= 0; i--) {
			happy += happen[tempPath[i]];
		}
		int avg = happy / (tempPath.size() - 1);
		if(happy > ansHappy) {
			ansHappy = happy;
			path = tempPath;
			avgHappy = avg;
		} else if(happy == ansHappy && avg > avgHappy) {
			path = tempPath;
			avgHappy = avg;
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	cin >> n >> k >> start;
	fill(G[0], G[0] + maxn * maxn, INF);
	cityToId[start] = 0;
	idToCity[0] = start;
	string city1, city2;
	for(int i = 1; i < n; i++) {
		cin >> city1 >> happen[i];
		cityToId[city1] = i;
		idToCity[i] = city1;
	}
	int cost;
	for(int i = 0; i < k; i++) {
		cin >> city1 >> city2 >> cost;
		int id1 = cityToId[city1];
		int id2 = cityToId[city2];
		G[id1][id2] = G[id2][id1] = cost;
	}
	Dijkstra(0);
	DFS(cityToId[rom]);
	printf("%d %d %d %d\n", ansNum, d[cityToId[rom]], ansHappy, avgHappy);
	for(int i = path.size() - 1; i >= 0; i--) {
		cout << idToCity[path[i]];
		if(i > 0) cout << "->";
		else cout << endl;
	}
	return 0;
}
