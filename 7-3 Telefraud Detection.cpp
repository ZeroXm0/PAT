#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1010;
int k, n, m;
int duration[maxn][maxn]; 			//��¼ab��ͨ��������
bool vis[maxn];					//��¼�������Ƿ��Ѽ��� 
int father[maxn];
vector<int> sus;				//��¼������ 
map<int, vector<int> > res;
int find(int v) {
	int x = v;
	while(v != father[v]) {
		v = father[v];
	}
	while(x != father[x]) {
		father[x] = v;
		x = father[x];
	}
	return v;
}
void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa != fb) {
		fa < fb ? father[fb] = fa : father[fa] = fb;
	}
}
int main() {
	scanf("%d%d%d", &k, &n, &m);
	while(m--) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		duration[a][b] += d;
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) father[i] = i; 
	for(int i = 1; i <= n; i++) {
		int caller = 0, reciver = 0;
		for(int j = 1; j <= n; j++) {
			if(duration[i][j] > 0 && duration[i][j] <= 5) {
				caller++;
				if(duration[j][i] > 0) reciver++;
			}
		}
		if(caller > k && reciver * 5 <= caller) {
			bool flag = true;
			for(int j = 0;  j < sus.size(); j++) {
				if(duration[sus[j]][i] && duration[i][sus[j]]) {	
					Union(sus[j], i);				//�˴����ܵ����ж��Ƿ���ǰĳ��ͨ����ֱ�Ӻϲ�����Ϊ �����й�ͬͨ��Ҳ��һ�����ϣ������ò��鼯��6�ֲ��Ե� 
				}
			}
			sus.push_back(i);
		}
	}
	if(sus.empty()) printf("None\n");
	else {
		for(int i = 0; i < sus.size(); i++) {			//	�����Ǵ�С����ѭ���ģ����������� 
			res[find(sus[i])].push_back(sus[i]);
		}
		for(int i = 0; i < res.size(); i++) {
			if(res[i].size()) {
				for(int j = 0; j < res[i].size(); j++) {
					if(j != 0) printf(" ");
					printf("%d", res[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
} 
