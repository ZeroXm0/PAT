#include <stdio.h>
#include <string.h>

int main(){
	int result[55] = {}; 
  int b[55] = {};
  int c[55] = {};
  int n,i,k;
  scanf("%d\n", &n);
  for(i = 0; i < 54; i++){
  	result[i] = i;
  	scanf("%d", &b[i]); 
  } 
  for( k = 0; k < n; k++ ){
  	for( i = 0;i < 54; i++){
	  	int j = b[i] - 1;
		c[j] = result[i];
	  }
  	memcpy(result,c,sizeof(c));
  }
  
for(i=0; i<54; i++){ // 输出
        if(result[i]/13==0){
            // 花色为黑桃
            printf("%c%d", 'S',result[i]%13+1);
        }
        else if(result[i]/13==1){
            // 花色为红桃
            printf("%c%d", 'H',result[i]%13+1);
        }
        else if(result[i]/13==2){
            // 花色为梅花
            printf("%c%d", 'C',result[i]%13+1);
        }
        else if(result[i]/13==3){
            // 花色为方块
            printf("%c%d", 'D',result[i]%13+1);
        }
        else{
            // 花色为小丑
            printf("%c%d", 'J',result[i]%13+1);
        }
        if(i<53){
            printf(" ");
        }
    } 
  
}
