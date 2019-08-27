#include <iostream>
#include <vector>
using namespace std;
bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int tsize, n, m, a;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isprime(tsize)) tsize++;
    vector<int> v(tsize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < tsize; j++) {
            int pos = (a + j * j) % tsize;
            if (v[pos] == 0) {
                v[pos] = a;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        bool flag = false;
        for (int j = 0; j < tsize; j++) {
            ans++;
            int pos = (a + j * j) % tsize;
            if (v[pos] == a || v[pos] == 0) {
                flag = true;
                break;
            }
        }
        if(flag == false) ans++; 
		//j <= Tsize-1 范围内没有找到，并且不确定是否有该元素，则说明该元素无法插入，将查询总数+1(找到次数最大为tsize，没找到 +1到达查找上限说明找不到了） 
    }
    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}
