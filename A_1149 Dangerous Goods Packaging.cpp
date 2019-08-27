#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int n, m, k;
map<int, vector<int> > in;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		in[a].push_back(b);
		in[b].push_back(a);
	}
	while(m--) {
		scanf("%d", &k);
		bool mark = true;
		vector<int> list(k);
		map<int, bool> flag;
		for(int j = 0; j < k; j++) {
			scanf("%d", &list[j]);
			if(flag[list[j]] == true) {
				mark = false;
			}
			if(mark == true) {
				int num = in[list[j]].size();
				for(int it = 0; it < num; it++) {
					flag[in[list[j]][it]] = true;
				}	
			}
		}
		if(mark == false) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
