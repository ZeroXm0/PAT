#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, ori[maxn], change[maxn], tempOri[maxn];
bool isSame(int a[], int b[]) {
	for(int i = 1; i <= n; i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}
void printArr(int a[]) {
	for(int i = 1; i <= n; i++){
		printf("%d", a[i]);
		if(i != n) printf(" ");
		else printf("\n");
	}
}
bool insertSort() {
	bool flag = false;
	for(int i = 2; i < n; i++) {
		if(i != 2 && isSame(tempOri, change) ){
			flag = true;
		}
		sort(tempOri, tempOri + i + 1);
		if(flag == true)	return true;
	}
	return false;
}
void downAdj(int low, int high) {
	int i = low, j = i * 2;
	while(j <= high) {
		if(j + 1 <= high && tempOri[j + 1] > tempOri[j]) j = j + 1;
		if(tempOri[j] > tempOri[i]) {
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		} else {
			break;
		}
	}
}
void heapSort() {
	bool flag = false;
	for(int i = n / 2; i >= 1; i--) {
		downAdj(i, n);
	}
	for(int i = n; i > 1; i--) {
		if(i != n && isSame(tempOri, change) ) flag = true;
		swap(tempOri[1], tempOri[i]);
		downAdj(1, i - 1);
		if(flag == true) {
			printArr(tempOri);
			return;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &ori[i]);
		tempOri[i] = ori[i];
	}
	for(int i = 1; i <= n; i++) scanf("%d", &change[i]);
	if(insertSort() == true) {
		printf("Insertion Sort\n");
		printArr(tempOri); 
	} else {
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++) tempOri[i] = ori[i];
		heapSort();
	}
	return 0;
} 
