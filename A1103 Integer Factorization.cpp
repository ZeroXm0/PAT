#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
/*
	从小到大加入temp 超时 
	参考算法笔记，
	①从大到小遍历，减少运算，降低复杂度 
	②pow运算在DFS中使复杂的提高
	所以建立	fac 先按从大到小排序并计算pow 
*/
vector<int> fac, temp, ans;
int n, k, p, maxn = 0;
void init() {
	//从0 开始方便使用 fac[index] ，0实际上不会被使用到，但数组下标和index都是从fac.size() - 1 开始 
	int i = 0, t = 0;
	while(t <= n){				//i^p不超过n时继续加入
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
	if(index - 1 >= 0) {		//注意	=	不选择时可行 
		// 选择 index 
		temp.push_back(index);
		DFS(index, nowSum + index, nowK + 1, Fsum + fac[index]);
		temp.pop_back();
		// 不选择 index 
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
