#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
	����һ�汾�У��������ʱ��
	�ο��㷨�ʼǣ� �½���һ��fact��
	�Ӵ�С������������֤�ˣ��ȱ�������ans[i] һ���Ǵ��� temp[i]
	�������㣬���͸��Ӷ� 
*/
vector<int> temp, ans;
int n, k, p, maxn = 0;
bool cmp() {
	for(int i = 0; i < k; i++) {
		if(temp[i] != ans[i]) {
			return temp[i] > ans[i];
		}
	}
	return false;
}
void DFS(int index, int nowSum, int nowK, int Fsum) {
	if(nowK == k && Fsum == n) {
		if(Fsum > maxn || (Fsum == maxn && cmp() == true)) {
			maxn = Fsum;
			ans = temp;
		}
		return;
	}
	if(index > n || Fsum > n || nowK > k)	return;
	// ѡ�� index 
	temp.push_back(index);
	DFS(index, nowSum + index, nowK + 1, Fsum + pow(index, p));
	temp.pop_back();
	// ��ѡ�� index 
	DFS(index + 1, nowSum, nowK, Fsum); 
}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	DFS(1, 0, 0, 0);
	if(ans.size() == k) {
		printf("%d =", n);
		for(int i = k - 1; i >= 0; i--) {
			printf(" %d^%d", ans[i], p);
			if(i != 0) printf(" +");
			else printf("\n");
		}
	} else {
		printf("Impossible\n");
	}
} 
