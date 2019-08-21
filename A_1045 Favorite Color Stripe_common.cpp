#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int maxc = 10010;
int A[maxn], B[maxc], D[maxn][maxc];
int main() {
	int n, m, l;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &l);
	for(int i = 1; i <= l; i++) {
		scanf("%d", &B[i]);
	}
	for(int i = 0; i <= m; i++)	D[i][0] = 0;
	for(int i = 0; i <= l; i++)	D[0][i] = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= l; j++) {			//简化，相等时比不相等+1 
			int MAX = max(D[i - 1][j], D[i][j - 1]);
			if(A[i] == B[j]) {
				D[i][j] = MAX + 1;
			} else {
				D[i][j] = MAX;
			}
		}
	}
	printf("%d\n", D[m][l]);
	return 0;
}
