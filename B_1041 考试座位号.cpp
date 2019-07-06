#include <cstdio>
#include <cstring>
struct person {
	char id[20];
	int first;
	int last;
}person[1010];

int main() {
	int n,m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", person[i].id, &person[i].first, &person[i].last);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int search;
		scanf("%d", &search);
		for(int j = 0; j < n; j++) {
			if(person[j].first == search) printf("%s %d\n", person[j].id,  person[j].last);
		}
	}
	return 0;
}
