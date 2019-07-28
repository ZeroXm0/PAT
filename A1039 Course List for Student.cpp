#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 40010;
const int M = 26 * 26 * 26 * 10 + 1;	//����������3��Ӣ����ĸ��һ���������
vector<int> selectCourse[M];	//ÿ��ѧ��ѡ��Ŀγ̱��

int getID(char name[] ) {
	int id = 0;
	for(int i = 0; i < 3; i++) {
		id = id * 26 + ( name[i] - 'A' );	//26����ĸ 
	} 
	id = id * 10 + (name[3] - '0');
	return id;
} 
int main() {
	char name[5];
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++) {
		int course, x;
		scanf("%d%d", &course, &x);
		while(x--) {
			scanf("%s", name);
			int id = getID(name);
			selectCourse[id].push_back(course);
		}
	}
	for(int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getID(name);
		printf("%s %d", name, selectCourse[id].size());
		sort(selectCourse[id].begin(), selectCourse[id].end());
		for(int j = 0; j < selectCourse[id].size(); j++) {
			printf(" %d",selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
} 
