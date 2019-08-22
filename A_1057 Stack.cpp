#include <cstdio> 
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 100010;
const int sqr = 316;
stack<int> st;
int block[sqr], table[maxn];
void peekMedian(int k) {
	int sum = 0, idx = 0;
	while(sum + block[idx] < k) {
		sum += block[idx++];
	}
	int num = idx * sqr;
	while(sum + table[num] < k) {
		sum += table[num++];
	}
	printf("%d\n", num);
}
void spush(int v) {
	st.push(v);
	block[v / 316]++;
	table[v]++;
}
void spop() {
	int v = st.top();
	st.pop();
	block[v / 316]--;
	table[v]--;
	printf("%d\n", v);
}
int main() {
	int n;
	scanf("%d", &n);
	char str[20];
	while(n--) {
		scanf("%s", str);
		if(strcmp(str, "Push") == 0) {
			int s;
			scanf("%d", &s);
			spush(s);
		} else if(strcmp(str, "Pop") == 0) {
			if(st.empty()) {
				printf("Invalid\n");
			} else {
				spop();
			}
		} else {
			if(st.empty()) {
				printf("Invalid\n");
			} else {
				int k = st.size();
				if(k % 2 == 1) {
					k = (k + 1) / 2;
				} else {
					k /= 2;
				}
				peekMedian(k);
			} 
		}
	}
	return 0;
}
