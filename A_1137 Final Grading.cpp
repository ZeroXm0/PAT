#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
struct node{
	string name;
	int Gp, Gm, Gf, G;
};
vector<node> stu;
map<string, int> order;
int p, m, n, grade;
string str;
bool cmp(node a, node b) {
	if(a.G != b.G) return a.G > b.G;
	else return a.name < b.name;
}
int main() {
	int cnt = 1;
	cin >> p >> m >> n;
	while(p--) {
		cin >> str >> grade;
		if(grade >= 200) {
			stu.push_back(node{str, grade, -1, -1, 0});
			order[str] = cnt++;
		}
	}
	while(m--) {
		cin >> str >> grade;
		if(order[str] != 0) {
			stu[order[str] - 1].Gm = grade;
		} else {
			stu.push_back(node{str, -1, grade, -1, 0});
			order[str] = cnt++;
		}
	}
	while(n--) {
		cin >> str >> grade;
		if(order[str] != 0) {
			stu[order[str] - 1].Gf = grade;
			if(grade >= stu[order[str] - 1].Gm) {
				stu[order[str] - 1].G = grade;
			} else {
				stu[order[str] - 1].G = round(0.4 * stu[order[str] - 1].Gm + 0.6 * grade);
			}
		} else {
			stu.push_back(node{str, -1, -1, grade, grade});
			order[str] = cnt++;
		}
	}
	sort(stu.begin(), stu.end(), cmp);
	map<string, node>::iterator it;
	for(int i = 0; i < stu.size(); i++) {
		if(stu[i].G >= 60 && stu[i].Gp != -1)
			cout << stu[i].name << " " << stu[i].Gp << " " << stu[i].Gm << " " << stu[i].Gf << " " << stu[i].G << endl;
	}
	return 0;
}
