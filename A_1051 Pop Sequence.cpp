#include <cstdio>
#include <stack>
using namespace std;
int main() {
	stack<int> sta;
	int m, n, t;
	scanf("%d%d%d", &m, &n, &t);
	while(t--) {
		while(sta.empty() == false) sta.pop();
		int count = 0, i, num, flag = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &num);
			while(sta.empty() || (sta.size() < m && sta.top() < num ) ) {
				sta.push(++count);
			}
			if(sta.top() == num){			//ע�ⲻ��������˳�ѭ���� ��������δ���룬 break ������iֵ��������������ȫ������������� 
				sta.pop();
			}else {
				flag = 1;
			}
		}
		if(flag == 0 && sta.empty()) printf("YES\n");		//�����ж�empty �������Էǿ� ���Ϸ� 
		else printf("NO\n");
	}
	return 0;
} 
