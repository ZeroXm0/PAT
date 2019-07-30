#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 101;
int n;
struct standara{		//�����ѧ������ 
	int num[maxn];
	int k;
	standara() {
		memset(num, 0, sizeof(num));
		k = 0;
	}
};
standara change(string a) {
	standara res;
	int cnum = 0, del = 0;
	bool flag = 0;
	while(a.length() > 0 && a[0] == '0') a.erase(a.begin());
	if(a[0] == '.'){
		flag = 1;		//���С���� ��ɾ��С������ǰ��0 ��ÿɾ��һ��С�����0 ָ��-1 
		a.erase(a.begin());
		while(a.length() > 0 && a[0] == '0'){
			a.erase(a.begin());
			res.k--;
		}
	}
	if(a.length() == 0) res.k = 0;		//��ȥǰ��0 Ϊ0 ˵����Ϊ0�� ָ��Ϊ0 
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != '.' && flag == 0){		//С����ǰ��ָ������ 
			res.num[cnum++] = a[i] - '0';
			res.k++;
		} else if(a[i] == '.') {		//����С�����ָ���������� 
			flag = 1;
		} else {
			res.num[cnum++] = a[i] - '0';
		}
	}
	while(cnum < n) {			//�������ֲ��㲹0 
		res.num[cnum++] = 0;
	}
	return res;
}
bool cmp(standara a, standara b) {
	if(a.k != b.k) return false;
	else {
		for(int i = 0; i < n; i++) {
			if(a.num[i] != b.num[i]) return false; 
		}
	}
	return true;
}
void printfSta(standara a) {			//��ӡ��ѧ������ 
	printf(" 0.");
	for(int i = 0; i < n; i++) printf("%d", a.num[i]);
	printf("*10^%d", a.k);
}
int main() {
	string a, b;
	cin >> n >> a >> b;	
	standara str1, str2;
	str1 = change(a);			//ת��Ϊ��ѧ������ 
	str2 = change(b);
	if(cmp(str1, str2) == true) {
		printf("YES");
		printfSta(str1);
	} else {
		printf("NO");
		printfSta(str1);
		printfSta(str2);
	}
	printf("\n");
	return 0; 
}
