#include <stdio.h>
#include <iostream>
#include <string.h>
 using namespace std;
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d; 
	string day[8] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

	int count = 0;
	for( int j = 0 ; j < a.size() && j < b.size(); j++){
		if (a[j] == b[j] && a[j]>='A'&& a[j]<='G' && count == 0){
			count++;
			cout<<day[a[j] - 'A']<< " ";
		}else if(a[j] == b[j] && count == 1){
			if(a[j]>= '0' && a[j]<= '9'){
				printf("%02d:",a[j] - '0'); //×¢ÒâÉóÌâ 
				break;
			}else if(a[j]>= 'A' && a[j]<= 'N'){
				printf("%02d:",a[j] - 'A' + 10);
				break;
			}
			
		}
	}
	for(  int j = 0 ; j < c.size() && j < d.size(); j++){
		if (c[j] == d[j] ){
			if((c[j]>='A'&& c[j]<='Z') || (c[j]>='a'&& c[j]<='z')){
				printf("%02d",j);
				return 0;
			}
			
		} 
	}
}
