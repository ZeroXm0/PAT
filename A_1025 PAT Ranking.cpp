 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 struct testee {
 	char id[15];
 	int score;
 	int team;
 	int t_rank;
 } test[30011];
 bool cmp(testee a, testee b) {
 	if(a.score != b.score) return a.score > b.score;
 	else return strcmp(a.id, b.id) < 0;
 }
 
 
 int main() {
 	int n,k,count = 0;
 	scanf("%d", &n);
 	for(int i = 1; i <= n; i++) {
 		scanf("%d", &k);
 		for(int j = 0; j < k; j++) {
 			scanf("%s %d", test[count].id, &test[count].score);
 			test[count].team = i;
 			count++; 
		 }
		sort(test + count - k, test + count, cmp);
 		test[count - k].t_rank = 1;
 		for(int m = count - k +1; m < count; m++) {
	 		if(test[m].score == test[m - 1].score) test[m].t_rank = test[m - 1].t_rank;
	 		else test[m].t_rank = m + 1 - (count - k);
	 	} 
	 }
	 printf("%d\n", count);
 	sort(test, test + count, cmp);
 	int r = 1;
 	for(int i = 0; i < count; i++) {
	 	if(i > 0 & test[i].score != test[i - 1].score) r = i + 1;
	 	printf("%s %d %d %d\n", test[i].id, r, test[i].team, test[i].t_rank);
	 } 

 	
 	return 0;
 } 
