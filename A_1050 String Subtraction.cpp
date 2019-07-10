#include <stdio.h>
#include <string.h>
#include<iostream>
    using namespace std;

int main(){
	char str1[10001];
	char str2[10002];
	bool status[10001] = {false};
	
	cin.getline(str1,10001);
    cin.getline(str2,10002);

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	for(int i = 0; i < len2; i++) status[str2[i]] = true;
	for(int j = 0; j < len1; j++){
		if(!status[str1[j]]) printf("%c",str1[j]);
	}
	return 0;
}
