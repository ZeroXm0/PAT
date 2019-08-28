#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;
map<int, int> Marry;
set<int> single;
map<int, bool> in;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		Marry[p1] = p2;
		Marry[p2] = p1;
	}
	int m;
	scanf("%d", &m);
	vector<int> people(m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &people[i]);
		in[people[i]] = true;
	}
	for(int i = 0; i < m; i++) {
		int partner = Marry[people[i]];
		if(!in[partner]) {
			single.insert(people[i]);
		} 
	}
	printf("%d\n", single.size());
	if(single.size() > 0) {
		set<int>::iterator it = single.begin();
		printf("%05d", *it);
		it++;
		for(; it != single.end(); it++) {
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
