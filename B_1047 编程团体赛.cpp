#include <cstdio>

int main() {
	int n, team, id, score;
	scanf("%d", &n);
	int hash[1010] = {0};
	for(int i = 0; i < n; i++) {
		scanf("%d-%d %d", &team, &id, &score);
		hash[team] += score;
	}
	int k = 1;
	for(int i = 1; i < 1010; i++) {
		if(hash[i] > hash[k]) k = i;
	}
	printf("%d %d\n", k, hash[k]);
}
