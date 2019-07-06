#include <cstdio> 
#include <algorithm>
using namespace std;

const int maxn = 100005;
int dist[maxn], a[maxn]; //dist[i] 从1到i+1的距离（从1+到i条道路） 
int main() {
	int  sum = 0, n, m, left, right;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		dist[i] = sum;
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &left, &right);
		if(left > right) swap(left,right);
		int temp = dist[right - 1] - dist[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
	
}
