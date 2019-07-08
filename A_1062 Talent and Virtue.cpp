#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct person {
	char id[10];
	int virtue,talent,sum;
	int flag; //定义考生类别 
} temp[100010];

bool cmp(person a, person b) {
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.virtue != b.virtue) return a.virtue > b.virtue;
	else return strcmp(a.id,b.id) < 0;
}

int main() {
	int n,l,h,count = 0;
	scanf("%d %d %d", &n, &l, &h);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", temp[i].id, &temp[i].virtue, &temp[i].talent);
		if(temp[i].virtue < l || temp[i].talent < l){
			temp[i].flag = 5;
			count++;
		}else if(temp[i].virtue >= h && temp[i].talent >= h) temp[i].flag = 1;
		else if(temp[i].virtue >= h) temp[i].flag = 2;
		else if(temp[i].virtue >= temp[i].talent) temp[i].flag = 3;
		else temp[i].flag = 4;
		temp[i].sum = temp[i].virtue + temp[i].talent;
	}
	
	printf("%d\n", n - count);
	int r = 1;
	sort(temp, temp + n, cmp);
	for(int i = 0; i < n; i++) {
		if(temp[i].flag != 5) {
			printf("%s %d %d\n", temp[i].id, temp[i].virtue, temp[i].talent);
		}
	}
	return 0;
}
