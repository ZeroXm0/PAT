#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	char str[110];
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++) {
		cin.getline(str, 110);
		int x, y, z;
		int num_p = 0, num_t = 0, other = 0;
		int loc_p = -1, loc_t = -1;
		int len = strlen(str);
		for(int j = 0; j < len; j++) {
			if(str[j] == 'P') {
				num_p++;
				loc_p = j;
			}else if(str[j] == 'T') {
				num_t++;
				loc_t = j;
			} else if(str[j] != 'A') {
				other++;
			}
		}
		if(num_p != 1 || num_t != 1 || other != 0 || loc_t - loc_p < 2){
			printf("NO\n");
			continue;
		}
		x = loc_p, y = loc_t - loc_p - 1, z = len - loc_t - 1;
		if(z - x * (y - 1) == x) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
