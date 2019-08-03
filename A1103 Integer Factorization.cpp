#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
	��С�������temp ��ʱ 
	�ο��㷨�ʼǣ�
	�ٴӴ�С�������������㣬���͸��Ӷ� 
	��pow������DFS��ʹ���ӵ����
	���Խ���	fac �Ȱ��Ӵ�С���򲢼���pow 
*/
vector<int> fac, temp, ans;
int n, k, p, maxn = 0;
void init() {
	//��0 ��ʼ����ʹ�� fac[index] ��0ʵ���ϲ��ᱻʹ�õ����������±��index���Ǵ�fac.size() - 1 ��ʼ 
	int i = 0, t = 0;
	while(t <= n){				//i^p������nʱ��������
		fac.push_back(t);
		t = pow(++i, p); 
	}
}
void DFS(int index, int nowSum, int nowK, int Fsum) {
	if(nowK == k && Fsum == n) {
		if(nowSum > maxn) {
			maxn = nowSum;
			ans = temp;
		}
		return;
	}
	if(Fsum > n || nowK > k)	return;
	if(index - 1 >= 0) {		//ע��	=	��ѡ��ʱ���� 
		// ѡ�� index 
		temp.push_back(index);
		DFS(index, nowSum + index, nowK + 1, Fsum + fac[index]);
		temp.pop_back();
		// ��ѡ�� index 
		DFS(index - 1, nowSum, nowK, Fsum); 
	}

}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if(ans.size() == k) {
		printf("%d =", n);
		for(int i = 0; i < k; i++) {
			printf(" %d^%d", ans[i], p);
			if(i != k - 1) printf(" +");
			else printf("\n");
		}
	} else {
		printf("Impossible\n");
	}
} 
