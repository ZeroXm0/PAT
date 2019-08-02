#include <cstdio>
#include <stack>
using namespace std;
int main() {
	stack<int> sta;
	int m, n, t;
	scanf("%d%d%d", &m, &n, &t);
	while(t--) {
		while(sta.empty() == false) sta.pop();
		int count = 0, i, num, flag = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &num);
			while(sta.empty() || (sta.size() < m && sta.top() < num ) ) {
				sta.push(++count);
			}
			if(sta.top() == num){			//注意不满足如果退出循环则 还有数据未读入， break 后再用i值输入会出错，建议先全部输入存入数组 
				sta.pop();
			}else {
				flag = 1;
			}
		}
		if(flag == 0 && sta.empty()) printf("YES\n");		//必须判断empty 处理完仍非空 不合法 
		else printf("NO\n");
	}
	return 0;
} 
