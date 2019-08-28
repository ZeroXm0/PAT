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
		if(p1 == 0) p1 = 111111;		//特别注意0的情况，map 对应的初始为0 
		if(p2 == 0) p2 = 111111; 
 		Marry[p1] = p2;
		Marry[p2] = p1;
	}
	int m;
	scanf("%d", &m);
	vector<int> people(m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &people[i]);
		if(people[i] == 0) people[i] = 111111;
		in[people[i]] = true;
	}
	for(int i = 0; i < m; i++) {
		int partner = Marry[people[i]];
		if(in[partner] == false) {
			single.insert(people[i]);
		} 
	}
	printf("%d\n", single.size());
	if(single.size() > 0) {
		set<int>::iterator it = single.begin();
		if( *it == 111111) {
			printf("00000");
		}else {
			printf("%05d", *it);
		}
		it++;
		for(; it != single.end(); it++) {
			if(*it == 111111) {
				printf(" 00000");
			}else printf(" %05d", *it);
		}
		printf("\n");
	}
	return 0;
}
