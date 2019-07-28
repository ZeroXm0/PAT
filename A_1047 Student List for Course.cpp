#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
 using namespace std;
 const int M = 40010;
 const int N = 2510;
 vector<int> theCourse[M];
 char name[N][5];
 bool cmp (int a, int b) {
 	return strcmp(name[a], name[b]) < 0;
 }
 
 int main() {
 	int n, k;
 	scanf("%d%d", &n, &k);
 	for(int i = 0; i < n; i++) {
 		int size;
 		scanf("%s %d", name[i], &size);
 		for(int j = 0; j < size; j++) {
 			int c;
 			scanf("%d", &c);
 			theCourse[c].push_back(i);
		 }
	 }
	 for(int i = 1; i <= k; i++) {
	 	int size = theCourse[i].size();
	 	printf("%d %d\n", i, size);
	 	sort(theCourse[i].begin(), theCourse[i].end(), cmp);
	 	for(int j = 0; j < size; j++) printf("%s\n", name[theCourse[i][j]]);
	 }
	 return 0;
 }
