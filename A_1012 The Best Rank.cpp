#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct student {
	int id;
	int grade[4];
}stu[2010];

char course[4] = {'A','C','M','E'};
int Rank[1000000][4];//��¼����������
int now;//��now����

bool cmp(student a, student b) {
	return a.grade[now] > b.grade[now];
} 

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %dn", &stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;//���A���������� 
	}

	for(now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][now] = 1;
		for(int i = 1;i < n; i++){
			if(stu[i].grade[now] != stu[i - 1].grade[now]) Rank[stu[i].id][now] = i + 1;
			else Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
		}       
	}
	
	
	int find;
	for(int i = 0; i < m; i++) {
		scanf("%d", &find);
		if(Rank[find][0] == 0) printf("N/A\n");
		else {
			int k = 0;
			for(int j = 0; j < 4; j++) {
				if(Rank[find][j] < Rank[find][k]) k = j;
			}
			printf("%d %c\n",Rank[find][k], course[k]);
		} 
		
	}
	return 0;
}