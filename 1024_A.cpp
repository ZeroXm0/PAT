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
  
for(i=0; i<54; i++){ // ���
        if(result[i]/13==0){
            // ��ɫΪ����
            printf("%c%d", 'S',result[i]%13+1);
        }
        else if(result[i]/13==1){
            // ��ɫΪ����
            printf("%c%d", 'H',result[i]%13+1);
        }
        else if(result[i]/13==2){
            // ��ɫΪ÷��
            printf("%c%d", 'C',result[i]%13+1);
        }
        else if(result[i]/13==3){
            // ��ɫΪ����
            printf("%c%d", 'D',result[i]%13+1);
        }
        else{
            // ��ɫΪС��
            printf("%c%d", 'J',result[i]%13+1);
        }
        if(i<53){
            printf(" ");
        }
    } 
  
}
