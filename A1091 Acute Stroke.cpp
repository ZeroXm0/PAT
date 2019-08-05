#include <cstdio>
#include <queue>
using namespace std;
int m, n, l, t;
bool inq[1300][130][61] = {false};
int pixe[1300][130][61];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
struct Node{
	int x, y, z;
} node;
bool judge(int x, int y, int z) {
	if(x >= m || x < 0 || y >= n || y < 0 || z >= l || z < 0)	return false;
	if(pixe[x][y][z] == 0 || inq[x][y][z] == true)	return false;
	return true;
}
int BFS(int x, int y, int z) {
	int now = 0;
	queue<Node> q;
	node.x = x, node.y = y, node.z = z;
	q.push(node);
	inq[x][y][z] = true;
	while(!q.empty()) {
		Node top = q.front();
		q.pop();
		now++;
		for(int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)) {
				node.x = newX, node.y = newY, node.z = newZ;
				q.push(node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(now >= t)	return now;
	else return 0;
}
int main() {
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int z = 0; z < l; z++) {
		for(int x = 0; x < m; x++) {
			for(int y = 0; y < n; y++) {
				scanf("%d", &pixe[x][y][z]);
			}
		}
	} 
	int ans = 0;
	for(int z = 0; z < l; z++) {
		for(int x = 0; x < m; x++) {
			for(int y = 0; y < n; y++) {
				if(pixe[x][y][z] == 1 && inq[x][y][z] == false){
					ans += BFS(x, y, z);
				}
			}
		}
	} 
	printf("%d\n", ans);
	return 0;
}
