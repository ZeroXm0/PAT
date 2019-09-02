#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 21;
struct node {
	string s;
	int l, r;
} node[maxn]; 
bool vis[maxn];
int k;
void DFS(int root) {
	if(root == -1) return;
	if(root != k && (node[root].l != -1 || node[root].r != -1)) cout << "(";
	DFS(node[root].l);
	cout << node[root].s;
	DFS(node[root].r);
	if(root != k && (node[root].l != -1 || node[root].r != -1)) cout << ")";
}
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> node[i].s >> node[i].l >> node[i].r;
		if(node[i].l != -1) vis[node[i].l] = true;
		if(node[i].r != -1) vis[node[i].r] = true;
	}
	k = 1;
	while(vis[k]) {
		k++; 
	} 
	DFS(k);
	return 0;
}
