#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
	在这一版本中，会产生超时，
	参考算法笔记， 新建立一个fact，
	从大到小遍历，这样保证了，先遍历到的ans[i] 一定是大于 temp[i]
	减少运算，降低复杂度 
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
	// 选择 index 
	temp.push_back(index);
	DFS(index, nowSum + index, nowK + 1, Fsum + pow(index, p));
	temp.pop_back();
	// 不选择 index 
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
