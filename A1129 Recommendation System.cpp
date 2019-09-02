#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int book[50001];
struct node{
	int v, cnt;
	bool operator < (const node &a) const {
		return (cnt != a.cnt) ? cnt > a.cnt : v < a.v;
	}
};
int main() {
	int n, k, num;
	scanf("%d%d", &n, &k);
	set<node> s;
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		if(i != 0) {
			printf("%d:", num);
			int cnt = 0;
			for(set<node>::iterator it = s.begin(); cnt < k && it != s.end(); it++) {
				cnt++;
				printf(" %d", it->v);
			}
			printf("\n");
		}
		set<node>::iterator it = s.find(node{num, book[num]});
		if(it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node{num, book[num]});
	}
	return 0;
}
