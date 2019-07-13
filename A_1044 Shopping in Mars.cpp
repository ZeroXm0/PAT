#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sum[100010];
int nearm = 100000010;

int binarySearch(int left, int right, int m) {//�ҵ���һ������m�ĺ� 
	int mid;
	while(left < right) {
		mid = (left + right) / 2;
		if(sum[mid] > m) right = mid;
		else left = mid + 1;   
	}
	return left;
}


int main() {
	int n, m;
	sum[0] = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for(int i = 1; i <= n; i++) {//�ҳ�m������ӽ��Ĵ���m��ֵ 
		int ans = binarySearch(i, n + 1, sum[i - 1] + m);//��ʱ�ҵ���һ������m��ֵ(i-j)
		if(sum[ans - 1] - sum[i - 1] == m) {//i��ans - 1���õ���m ,����m��Ŀ������Һ�Ϊm�� 
			nearm = m;
			break; 
		}else if(ans <= n && sum[ans] - sum[i - 1] < nearm) {//i ~ ans - 1 С��m��Ŀ��Ϊ��С�Ĵ���m�ĺ� 
			nearm = sum[ans] - sum[i - 1];
		}
	} 
	for(int i = 1; i <= n; i++) {//����������˵� 
		int ans = binarySearch(i, n + 1, sum[i - 1] + nearm);//����Ŀ��ֵ��λ�� ���ҵ��Ҷ˵�
		if(sum[ans - 1] - sum[i - 1] == nearm) {//ֻ��Ҫ�͵�����С�� ����m��ֵ 
			printf("%d-%d\n", i, ans - 1);
		} 
	}
	return 0;
}
