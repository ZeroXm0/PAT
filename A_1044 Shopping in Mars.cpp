#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sum[100010];
int nearm = 100000010;

int binarySearch(int left, int right, int m) {//找到第一个大于m的和 
	int mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(sum[mid] > m) right = mid;
		else left = mid + 1;   
	}
	return left;
}


int main() {
	int n, m;
	sum[0] = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for(int i = 1; i <= n; i++) {//找出m或者最接近的大于m的值 
		int ans = binarySearch(i, n + 1, sum[i - 1] + m);//此时找到第一个大于m的值(i-j)
		if(sum[ans - 1] - sum[i - 1] == m) {//i到ans - 1正好等于m ,存在m则目标就是找和为m的 
			nearm = m;
			break; 
		}else if(ans <= n && sum[ans] - sum[i - 1] < nearm) {//i ~ ans - 1 小于m，目标为最小的大于m的和 
			nearm = sum[ans] - sum[i - 1];
		}
	} 
	for(int i = 1; i <= n; i++) {//遍历所有左端点 
		int ans = binarySearch(i, n + 1, sum[i - 1] + nearm);//查找目标值的位子 ，找到右端点
		if(sum[ans - 1] - sum[i - 1] == nearm) {//只需要和等于最小的 大于m的值 
			printf("%d-%d\n", i, ans - 1);
		} 
	}
	return 0;
}
