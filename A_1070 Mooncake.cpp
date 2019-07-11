#include <cstdio>
#include <algorithm>
using namespace std;
struct mooncake {
	double num;//库存量 
	double allPrice; //总售价 
	double  price;//单价 
}cake[1010];
bool cmp (mooncake a, mooncake b) {
	return a.price > b.price;
} 

int main() {
	int n;
	double d, earn = 0;
	scanf("%d %lf", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%lf",&cake[i].num);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf",&cake[i].allPrice);
		cake[i].price = cake[i].allPrice / cake[i].num;
	}
	sort(cake, cake + n,cmp);
	for(int i = 0; i < n; i++) {
		if(d >= cake[i].num) {
			earn += cake[i].allPrice;
			d -= cake[i].num;
		}else{
			earn += cake[i].price * d;
			break;
		}
	} 
	printf("%.2f\n", earn);
	return 0;
}
