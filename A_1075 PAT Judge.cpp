#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,m;
struct student {
	int id,problem[6],total_score,perfect;
	bool flag;// id, 题号，总分，完美解决题数，是否通过编译 
} stu[100010], valid[100010];

bool cmp(student a, student b) {
	if(a.total_score != b.total_score) return a.total_score > b.total_score;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
} 

void init() {
	for(int i = 1; i <= n; i++) {
		stu[i].id = i;
		stu[i].total_score = 0;
		stu[i].perfect = 0;
		stu[i].flag = false;
		memset(stu[i].problem, -1, sizeof(stu[i].problem));
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	init();//初始化！！！！ 
	int full[6];
	for(int i = 1; i <= k; i++) scanf("%d", &full[i]);
	int uid, uproblem, uscore;
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &uid, &uproblem, &uscore);
		if(uscore != -1) stu[uid].flag = true;
		if(uscore == -1 && stu[uid].problem[uproblem] == -1){
			stu[uid].problem[uproblem] = 0;
		}
		if(uscore == full[uproblem] && stu[uid].problem[uproblem] < full[uproblem]) stu[uid].perfect++;
		if(uscore > stu[uid].problem[uproblem]) stu[uid].problem[uproblem] = uscore;
	}
	for(int i = 1; i <= n; i++) {
		stu[i].id = i;
		for(int j = 1; j <= k; j++) {
			if(stu[i].problem[j] != -1) stu[i].total_score += stu[i].problem[j];
		}
	} 
	sort(stu + 1, stu + n + 1, cmp);
	int r = 1;
	for(int i = 1; i <= n && stu[i].flag == true; i++) {
		if(i > 1 && stu[i].total_score < stu[i - 1].total_score) r = i;
		printf("%d %05d %d", r, stu[i].id, stu[i].total_score);
		for(int j = 1; j <= k; j++){
			if(stu[i].problem[j] != -1) printf(" %d", stu[i].problem[j]);
			else printf(" -");
		}
		printf("\n");
	}
	return 0;
}
