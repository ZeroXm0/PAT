#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 25;
int n, Max = -1, ans = -1;
struct Node{
	int left, right;
	Node() {
		left = right = -1;
	}
} node[maxn];
bool flag[maxn];
int toInt(char str[]) {
	int len = strlen(str);
	int sum = 0;
	for(int i = 0; i < len; i++) {
		sum = sum * 10 + str[i] - '0';
	}
	return sum;
} 
void DFS(int root, int index) {
	if(index > Max) {
		Max = index;
		ans = root;
	} 
	if(node[root].left != -1) DFS(node[root].left, index * 2);
	if(node[root].right != -1) DFS(node[root].right, index * 2 + 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		char left[5], right[5];
		cin >> left >> right;
		if(strcmp(left, "-") != 0) {
			node[i].left = toInt(left);
			flag[node[i].left] = true;
		}
		if(strcmp(right, "-") != 0) {
			node[i].right = toInt(right);
			flag[node[i].right] = true;
		}
	}
	int k;
	for(k = 0; k < n; k++) {
		if(flag[k] == false) break;
	}
	DFS(k, 1);
	if(Max > n) {
		printf("NO %d\n", k);
	} else {
		printf("YES %d\n", ans);
	}
	return 0;
} 
