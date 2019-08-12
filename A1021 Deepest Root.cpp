#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100010;
int n, deepest = 0;
int father[maxn];
bool isRoot[maxn] = {false};
vector<int> G[maxn];
set<int> ans, temp;
void init() {
	for(int i = 1; i <= n; i++){
		father[i] = i;
	}
}
int findFather(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];
	}
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = a;
	}
	return x;
}
void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa != fb) {
		father[fa] = fb;
	}
}
int cal() {
	int num = 0;
	for(int i = 1; i <= n; i++) {
		if(isRoot[findFather(i)] == false) {
			isRoot[findFather(i)] = true;
			num++; 
		}
	}
	return num;
}
void DFS(int x, int height, int pre) {
	if(height > deepest) {
		deepest = height;
		temp.clear();
	}
	if(height == deepest) temp.insert(x);
	for(int i = 0; i < G[x].size(); i++) {
		if(G[x][i] == pre) continue;
		DFS(G[x][i], height + 1, x);
	}
}
int main() {
	scanf("%d", &n);
	init();
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);
	}
	int num = cal();
	if(num != 1) {
		printf("Error: %d components\n", num);
	} else {
		DFS(1, 0, -1);
		ans = temp;
		set<int>::iterator it = ans.begin();
		DFS(*it, 0, -1);
		for(set<int>::iterator it = temp.begin(); it != temp.end(); it++) {
			ans.insert(*it);
		}
		for(set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
			printf("%d\n", *it);
		}
	}
	return 0;
}
