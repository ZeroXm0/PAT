#include <cstdio>
#include <cstring>

struct student {
	char name[11];
	char gender;
	char id[11];
	int grade;
}student[101];
int main() {
	int n;
	scanf("%d", &n);
	int f = 0,m = 0;//��¼female �� male�ı�� 
	int f_grade = -1, m_grade = 101;//��ʼ���ɼ� 
	for(int i = 1; i <= n; i++) {
		getchar();
		scanf("%s %c %s %d", student[i].name, &student[i].gender, student[i].id, &student[i].grade);
		if(student[i].gender == 'F') {
			f = student[i].grade > f_grade ? i: f;
			f_grade = student[f].grade;//�Ƚ���������ɼ� 
		} else {
			m = student[i].grade < m_grade ? i: m;
			m_grade = student[m].grade;
		}
	}
	if(f == 0) printf("Absent\n");
	else printf("%s %s\n", student[f].name, student[f].id);
	if(m == 0) printf("Absent\n");
	else printf("%s %s\n", student[m].name, student[m].id);
	if(f != 0 && m != 0) printf("%d\n", student[f].grade - student[m].grade);
	else printf("NA\n");
	
	return 0;
}
