#include <cstdio>
#include <queue>
using namespace std;
struct mouse{
	int weight,level;
	mouse() {
		weight = 0;
		level = 0;
	}
}mouse[1010]; 

int main() {
	int np, ng;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++) {
		scanf("%d", &mouse[i].weight);
	}
	queue<int> q;
	for(int i = 0; i < np; i++) {
		int num;
		scanf("%d", &num);
		q.push(num);	
	}
	int temp = np, group;
	while(q.size() != 1) {
		if(temp % ng == 0) group = temp / ng;			//计算组数 
		else group = temp / ng + 1;
		for(int i = 0; i < group; i++) {
			int k = q.front();			//记录最大值下标 
			for(int j = i * ng; j < (i + 1) * ng && j < temp; j++) {			//注意最后一组数量可能不足ng，所以要判断j 小于当前 总数 
				int now = q.front();				//记录当前值下标 
				if(mouse[now].weight > mouse[k].weight) {
					k = now;
				}
				mouse[now].level = group + 1;
				q.pop(); 
			}
			q.push(k);				//存入当前组最大值 
		}
		temp = group;
	}
	if(q.size() == 1) {					//只剩一个时，即最大 
		mouse[q.front()].level = 1;
	}
	for(int i = 0; i < np; i++) {				//按原顺序输出 
		printf("%d", mouse[i].level);
		if(i == np - 1) printf("\n");
		else printf(" ");
	}
	return 0;
} 
