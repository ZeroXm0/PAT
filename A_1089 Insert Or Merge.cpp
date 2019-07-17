#include <cstdio>
#include <algorithm>
using namespace std;
int Origin[110], tempOrg[110], change[110];
int n;
bool isSame(int a[], int b[]) {
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
} 
void printRes(int a[]) {
	for(int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if(i != n - 1) printf(" ");
	}
	printf("\n");
}

bool insertSort() {
	bool flag = false;
	for(int i = 1; i < n; i++) {
		if(i != 1 && isSame(tempOrg,change)) flag = true;
		int temp = tempOrg[i], j = i;
		while(j > 0 && tempOrg[j - 1] > temp) {
			tempOrg[j] = tempOrg[j - 1];
			j--;
		}
		tempOrg[j] = temp;
		if(flag == true) return true;
	}
	return false; 
	
}

void mergeSort() {
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2) {
		if(step != 2 && isSame(Origin, change)) flag = true;
		for(int i= 0; i < n; i += step){
			sort( Origin + i,  Origin + min(i + step, n));
		}
		if(flag == true) {
			printRes(Origin);
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &Origin[i]);
		tempOrg[i] = Origin[i];
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &change[i]);
	}
	if(insertSort()) {
		printf("Insertion Sort\n");
		printRes(tempOrg);;
	} else {
		printf("Merge Sort\n");
		mergeSort();
	}
	return 0;
}
