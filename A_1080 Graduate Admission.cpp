#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student {
	int id;
	int ge,gi,total;
	int school[6];
	int r; 
}stu[40010];

struct school {
	int quota;
	int stuNum;
	int id[40010];
	int lastAdmin;
}sch[110];

bool cmp(student a, student b) {
	if(a.total != b.total) return a.total > b.total;
	else return a.ge > b.ge;
}

bool cmpId(int a, int b) {
	return stu[a].id < stu[b].id;
}


int main() {
    int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		scanf("%d", &sch[i].quota);
		sch[i].lastAdmin = -1;
		sch[i].stuNum = 0;
	}

	for(int i = 0; i < n; i++) {
		stu[i].id = i; 
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		stu[i].total = stu[i].ge + stu[i].gi;
		for(int j = 0; j < k; j++) { //��¼ÿ����ѡ���k��־Ը 
			scanf("%d", &stu[i].school[j]);
		}
	}
	sort(stu, stu + n, cmp);
	for(int i = 0; i < n; i++) {//ע�Ȿ�����б�Ŷ��Ǵ�0��ʼ��������������Ҳ��0 ~ n-1 
		if(i > 0 && stu[i].total == stu[i - 1].total && stu[i].ge == stu[i - 1].ge) stu[i].r = stu[i - 1].r;
		else stu[i].r = i;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++){
			int choice = stu[i].school[j];
			int num = sch[choice].stuNum;
			int last = sch[choice].lastAdmin;
			if(num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r)) {
				sch[choice].id[num] = i;
				sch[choice].lastAdmin = i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		if(sch[i].stuNum > 0) {
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpId);
			for(int j = 0; j < sch[i].stuNum; j++){
				printf("%d", stu[sch[i].id[j]].id);
				if(j < sch[i].stuNum - 1) printf(" "); 
			}
		}
		printf("\n");
	}
	
	return 0;
}
