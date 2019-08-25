#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std;
struct node{
	char name[20];
	int height;
} stu[10010];
bool cmp(node a, node b) {
	return a.height != b.height ? a.height > b.height : strcmp(a.name, b.name) < 0; 
}
int main() {
	int n, k, ans[10010];
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> stu[i].name >> stu[i].height;
	sort(stu, stu + n, cmp);
	int t = 0, row = k, m;
	while(row) {
		if(row == k) m = n / k + n % k;
		else m = n / k;
		ans[m / 2] = t;
		int j = m / 2 - 1;
		for(int i = t + 1; i < t + m; i += 2)
			ans[j--] = i;
		j = m / 2 + 1;
		for(int i = t + 2; i < t + m; i += 2)
			ans[j++] = i;
		cout << stu[ans[0]].name;
		for(int i = 1; i < m; i++)
			cout << " " << stu[ans[i]].name;
		cout << endl;
		row--, t += m;
	}
	return 0;
} 
