#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1010;
const ll mod = 1000000007;
const ll p = 10000019;
ll H1[maxn], H2[maxn], powP[maxn];
void init() {
	powP[0] = 1;
	for(int i = 1; i < maxn; i++) {
		powP[i] = (powP[i - 1] * p) % mod;
	}
}
//����hashֵ 
void calH(ll H[], string &str) {
	H[0] = str[0];
	for(int i = 1; i < str.length(); i++) {
		H[i] = (H[i - 1] * p + str[i]) % mod;
	}
}
//�����Ӵ�hashֵ 
int getCal(ll H[], int i, int j) {
	if(i == 0) return H[j];
	return ((H[j] - H[i - 1] * powP[j - i + 1]) % mod + mod) % mod;
}
int bindarySearch(int l, int r, int len, int i, int eveEve) {			//eveEve = 1 ��ʾ��ż�����Ĵ� 
	while(l < r) {
		int mid = (l + r) / 2;				//�뾶��һ�볤�ȿ�ʼѰ��,ע�����ҵ��±� 
		int H1L = i - mid + eveEve, H1R = i;
		int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + eveEve);
		int hash1 = getCal(H1, H1L, H1R);
		int hash2 = getCal(H2, H2L, H2R);
		if(hash1 != hash2) r = mid;				//�����ڣ�˵���뾶��С
		else l = mid + 1; 
	}
	return l - 1;
}
int main() {
	init();
	string str;
	getline(cin, str);
	calH(H1, str);
	reverse(str.begin(), str.end());
	calH(H2, str);
	int ans = 0;
//	����� 
	for(int i = 0; i < str.length(); i++) {
		//�����Ͻ�Ϊ���ҳ��Ƚ�Сֵ��һ,��ľ��Ǹ�С��+1��2 - 1
		int maxlen = min(i, (int) str.length() - 1 - i) + 1 ;
		int k = bindarySearch(0, maxlen, str.length(), i, 0);
		ans = max(ans, 2 * k + 1);
	}
//	ż���� 
	for(int i = 0; i < str.length(); i++) {
		//�����Ͻ�Ϊ���ҳ��Ƚ�Сֵ��һ,ע����Ϊ i + 1���ÿ�϶��Ϊ�е� 
		int maxlen = min(i + 1, (int) str.length() - 1 - i) + 1 ;
		int k = bindarySearch(0, maxlen, str.length(), i, 1);
		ans = max(ans, 2 * k);
	}
	printf("%d\n", ans);
	return 0;
}
