#include <cstdio>
#include <algorithm>
using namespace std;
struct person{
	int id, fid, mid, num, area, cid[10];
} data[1010];
struct Fam{
	int id, people;
	double area, num;
	bool flag = false;
}ans[10000];
int father[10000];
bool vis[10000];
int n, k;
int find(int x) {
	while(x != father[x])
		x = father[x];
	return x;
}
void Union(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa > fb) father[fa] = fb;
	if(fb > fa) father[fb] = fa;
}
bool cmp(Fam a, Fam b) {
	if(a.area != b.area) return a.area > b.area;
	else return a.id < b.id;
}
int main() {
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < 10000; i++) father[i] = i;
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
		vis[data[i].id] = true;
		if(data[i].fid != -1) {
			vis[data[i].fid] = true;
			Union(data[i].id, data[i].fid);
		}
		if(data[i].mid != -1) {
			vis[data[i].mid] = true;
			Union(data[i].id, data[i].mid); 
		}
		for(int j = 0; j < k; j++) {
			scanf("%d", &data[i].cid[j]);
			vis[data[i].cid[j]] = true;
			Union(data[i].id, data[i].cid[j]);
		}
		scanf("%d %d", &data[i].num, &data[i].area);
	}
	for(int i = 0; i < n; i++) {
		int id = find(data[i].id);
		ans[id].id = id;
		ans[id].num += data[i].num;
		ans[id].area += data[i].area;
		ans[id].flag = true;
	}
	for(int i = 0; i < 10000; i++) {
		if(vis[i] == true)
			ans[find(i)].people++;
		if(ans[i].flag) cnt++;
	} 
	for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
	}
	sort(ans, ans + 10000, cmp);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
	}
	return 0;
}
