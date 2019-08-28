#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
map<int, int> ranklist;
map<int, bool> flag;
bool isPrime(int p) {
	if(p == 1) return false;
	int sqr = (int)sqrt(1.0 * p);
	for(int i = 2; i <= sqr; i++) {
		if(p % i == 0) return false; 
	} 
	return true;
}
void print(int q) {
	if(ranklist[q] == 1) printf("Mystery Award\n");
	else if(isPrime(ranklist[q]) == true) printf("Minion\n");
	else printf("Chocolate\n");
	flag[q] = true;
}
int main() {
	int n, k;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int id;
		scanf("%d", &id);
		ranklist[id] = i;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		int query;
		scanf("%d", &query);
		printf("%04d: ", query);
		if(flag[query]) {
			printf("Checked\n");
		}else if(ranklist[query] == 0) {
			printf("Are you kidding?\n");
			flag[query] = true;
		} else {
			print(query);
		}
	}
	return 0;
}
