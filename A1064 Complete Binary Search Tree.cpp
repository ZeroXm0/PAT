#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
int n, num[maxn], CBT[maxn], ans = 0;
void inOrder(int root) {
	if(root > n)	return;
	inOrder(root * 2);				//������ 
	CBT[root] = num[ans++];			//�������ڵ�ȫ����ֵ���ˣ����ڵ� 
	inOrder(root * 2 + 1);			//������ 
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	} 
	sort(num, num + n);
	inOrder(1);				//���ڵ�Ϊ1
	for(int i = 1; i <= n; i++) {
		printf("%d", CBT[i]);
		if(i != n) printf(" ");
		else printf("\n");
	} 
	return 0;
} 
