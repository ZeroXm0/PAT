#include <stdio.h>
#include <map>
	using namespace std;

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	map<int,int> arr;
	int half = m * n / 2; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int k;
			scanf("%d", &k);
			arr[k]++;
			
			if(arr[k] > half){
				printf("%d", k);
				return 0;
			}
		}
	}
	return 0;
}
