#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 35;
int pre[maxn], post[maxn];
vector<int> in;
bool unique = true;
void getIn(int preL, int preR, int postL, int postR) {
	if(preL == preR) {
		in.push_back(pre[preL]);
		return;
	}
	if(pre[preL] == post[postR]) {
		int i = preL + 1;
		while(i <= preR && pre[i] != post[postR - 1]) i++;				//�ҵ��������ĸ���֮ǰ�����Ͷ����������� 
		if(i - preL > 1) {
			getIn(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
		} else {
			unique = false;
		}
		in.push_back(post[postR]);
		getIn(i, preR, postL + (i - preL - 1), postR - 1); 
	}
} 
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	getIn(0, n - 1, 0, n - 1);
	if(unique) printf("Yes\n");
	else printf("No\n");
	printf("%d", in[0]);
	for(int i = 1; i < in.size(); i++) {
		printf(" %d", in[i]);
	}
	printf("\n");
	return 0;
}
