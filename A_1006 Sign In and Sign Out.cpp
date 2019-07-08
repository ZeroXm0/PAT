#include <cstdio>
#include <cstring>

struct ID {
	char id_number[15];
	int sign_in_time[3];
	int sign_out_time[3];
}id[100];

int main() {
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%s %d:%d:%d %d:%d:%d", id[i].id_number,
		 &id[i].sign_in_time[0], &id[i].sign_in_time[1],&id[i].sign_in_time[2],
		 &id[i].sign_out_time[0], &id[i].sign_out_time[1],&id[i].sign_out_time[2]);
	}
	int in = 0, out = 0,in_time = 24 * 3600, out_time = 0;
	for(int i = 0; i < m; i++) {
		int sign_in = id[i].sign_in_time[0] * 3600 + id[i].sign_in_time[1] * 60 + id[i].sign_in_time[2];
		int sign_out = id[i].sign_out_time[0] * 3600 + id[i].sign_out_time[1] * 60 + id[i].sign_out_time[2];
		if(sign_in < in_time) {
			in_time = sign_in;
			in = i; 
		} 
		if(sign_out > out_time) {
			out_time = sign_out;
			out = i;
		}
	}
	printf("%s %s", id[in].id_number, id[out].id_number);
	return 0;
}
