#include <cstdio>
#include <cstring> 
#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	double ans, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		char a[100], b[100];
		cin >> a;
        sscanf(a, "%lf", &temp);			//这两个函数牢记 
		sprintf(b, "%.2f", temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            ans += temp;
            cnt++;
        }
	}
	if(cnt == 0) printf("The average of 0 numbers is Undefined\n");
	else if(cnt == 1) printf("The average of 1 number is %.2f\n", ans);
	else {
		printf("The average of %d numbers is %.2f\n", cnt, ans / cnt);
	}
	return 0;
}
