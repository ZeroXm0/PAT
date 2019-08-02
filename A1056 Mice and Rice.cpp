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
		if(temp % ng == 0) group = temp / ng;			//�������� 
		else group = temp / ng + 1;
		for(int i = 0; i < group; i++) {
			int k = q.front();			//��¼���ֵ�±� 
			for(int j = i * ng; j < (i + 1) * ng && j < temp; j++) {			//ע�����һ���������ܲ���ng������Ҫ�ж�j С�ڵ�ǰ ���� 
				int now = q.front();				//��¼��ǰֵ�±� 
				if(mouse[now].weight > mouse[k].weight) {
					k = now;
				}
				mouse[now].level = group + 1;
				q.pop(); 
			}
			q.push(k);				//���뵱ǰ�����ֵ 
		}
		temp = group;
	}
	if(q.size() == 1) {					//ֻʣһ��ʱ������� 
		mouse[q.front()].level = 1;
	}
	for(int i = 0; i < np; i++) {				//��ԭ˳����� 
		printf("%d", mouse[i].level);
		if(i == np - 1) printf("\n");
		else printf(" ");
	}
	return 0;
} 
