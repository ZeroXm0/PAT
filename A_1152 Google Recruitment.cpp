#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
} 

int main(){
    int l,k;
    scanf("%d %d", &l, &k);
    getchar();
    string s;//注意string和char使用上的差别 
    cin >> s;
    for(int i = 0; i <= l - k; i++){
        string str = s.substr(i,k);
        int temp = stoi(str);
        if(isPrime(temp)){
            cout << str;
            return 0;
        }
    }
    cout << "404";
    return 0;
}
