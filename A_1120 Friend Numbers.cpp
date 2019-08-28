#include <cstdio>
#include <set>
using namespace std;
set<int> s;
int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int v, sum = 0;
		scanf("%d", &v);
		while(v) {
			sum += v % 10;
			v /= 10;
		}
		s.insert(sum);
	}
	printf("%d\n", s.size());
	if(s.size() > 0) {
		set<int>::iterator it = s.begin();
		printf("%d", *it);
		for(it++; it != s.end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");	
	}
	return 0;
}
