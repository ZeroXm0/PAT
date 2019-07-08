#include <cstdio>
#include <algorithm>
#include <cstring>
using  namespace std;

struct Student {
	char name[15], id[15];
	int grade;
} stu[10010]; 

bool cmp(Student a, Student b) {
	if( a.grade != b.grade) return a.grade > b.grade;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n, left, right, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);\
	}
	sort(stu, stu + n, cmp);
	scanf("%d%d", &left, &right);
	for(int i = 0; i < n; i++) {
		if(stu[i].grade >= left && stu[i].grade <= right) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			count++;
		}
	}
	if(count == 0) printf("NONE\n");
}
