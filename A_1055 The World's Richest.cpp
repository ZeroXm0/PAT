#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
 
int Age[100010] = {0};
struct Person {
	char name[10];
	int age,rich;
}temp[100010],valid[100010];//���������/��ÿ�������ǰ100�����ڵ��� 

bool cmp (Person a, Person b) {
	if(a.rich != b.rich) return a.rich > b.rich;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", temp[i].name, &temp[i].age, &temp[i].rich);
	}
	
	sort(temp, temp + n, cmp);
	int validNum = 0;
	for(int i = 0; i < n; i++) {
		if(Age[temp[i].age] < 100) {
			Age[temp[i].age]++;
			valid[validNum++] = temp[i];
		}
	}
	int x, amin, amax;
	for(int i = 1; i <= k; i++) {
		scanf("%d %d %d", &x, &amin, &amax);
		printf("Case #%d:\n", i);
		int printNum = 0;
		for(int z = 0; z < validNum && printNum < x; z++) {//ע�⣬�˴�Ҫʹ��Ԥ����õ�ÿ��������ǰ100������ ������1���Ե���� 
			if( valid[z].age >= amin && valid[z].age <= amax ) {
				printf("%s %d %d\n", valid[z].name, valid[z].age, valid[z].rich);
				printNum++;
			} 
		}
		if(printNum == 0 )	printf("None\n"); 
	}
	return 0;
}
