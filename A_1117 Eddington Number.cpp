#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> day(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &day[i]);
	}
	sort(day.begin(), day.end(), cmp);
	int i;
	for(i = day.size() - 1; i >= 0; i--) {
		if(day[i] > i + 1) break;
	}
	printf("%d\n", i + 1);
	return 0;
}
