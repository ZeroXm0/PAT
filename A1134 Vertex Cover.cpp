#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<vector<int> > v(m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[i].push_back(a);
		v[i].push_back(b);
	}
	scanf("%d", &k);
	while(k--) {
		int nc, num;
		scanf("%d", &nc);
		vector<bool> hash(n);
		for(int i = 0; i < nc; i++) {
			scanf("%d", &num);
			hash[num] = true;
		}
		bool flag = true;
		for (int j = 0; j < m; j++) {
            if(hash[v[j][0]] == false && hash[v[j][1]] == false) {
            	flag = false;
			}
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
	}
	return 0; 
}
