#include <cstdio>

int main(){
	int pg, ps , pk, vg, vs, vk;
	scanf("%d.%d.%d %d.%d.%d", &pg, &ps, &pk, &vg, &vs, &vk);
	int p = pg * 17 * 29 + ps * 29 + pk;
	int v = vg * 17 * 29 + vs * 29 + vk;
	int change = v - p;
	if ( change < 0){
		printf("-");
		change = -change;
	}
	printf("%d.%d.%d\n", change/ (17 * 29),  change % (29 * 17 ) / 29 , change % 29);
	return 0;
} 
