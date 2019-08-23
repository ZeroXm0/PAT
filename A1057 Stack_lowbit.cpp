#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
#define lowbit(i)  ((i) & -(i))
const int maxn = 100010;
stack<int> st;
int c[maxn];
void update(int k, int v) {
	for(int i = k; i < maxn; i += lowbit(i)) {
		c[i] += v;
	}
}
int getSum(int k) {
	int sum = 0;
	for(int i = k; i > 0; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
int peekMedian() {
	int l = 1, r = maxn, mid, k = (st.size() + 1) / 2;
	while(l < r) {
		mid = (l + r) / 2;
		// 等于的情况其实就是mid 个，所以下一步在[l, mif]找，此时L实际上就=mid + 1,如果大于的话就不已经退出循环，如果放在下面则跳过了mid 
		if(getSum(mid) >= k) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);			//输出最左边即寻找到的 
} 
int main() {
	int n;
	char str[20];
	scanf("%d", &n);
	while(n--) {
		scanf("%s", str);
		if(strcmp(str, "Push") == 0) {
			int v;
			scanf("%d", &v);
			st.push(v);
			update(v, 1);
		} else if(strcmp(str, "Pop") == 0) {
			if(st.empty()) {
				printf("Invalid\n");
			} else {
				printf("%d\n", st.top());
				update(st.top(), -1);
				st.pop();
			}
		} else {
			if(st.empty())	printf("Invalid\n");
			else peekMedian();
		}
	}
}
