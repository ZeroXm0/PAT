#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
struct School {
	int r, ns, tws;
	double sum;
	string name;
} Sch[100010]; 
map<string, int> sch;
bool cmp (School a, School b) {
	if(a.tws != b.tws) return a.tws > b.tws;
	else if(a.ns != b.ns) return a.ns < b.ns;
	else return a.name < b.name;
}
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 1, sum = n;
	while(sum--) {
		string id, school;
		double score;
		cin >> id >> score >> school;
		for(int i = 0; i < school.length(); i++) {
			school[i] = tolower(school[i]);
		}
		if (id[0] == 'B') {
			score = score / 1.5;
		} else if(id[0] == 'T'){
			score = score * 1.5;
		}
		if(sch[school] != 0) {
			int idx = sch[school];
			Sch[idx].sum += score;
			Sch[idx].ns++;
		} else {
			sch[school] = cnt;
			Sch[cnt].name = school;
			Sch[cnt].sum = score;
			Sch[cnt++].ns = 1;
		}
	}
	for(int i = 1; i < cnt; i++) {				//תΪTWS 
		Sch[i].tws = (int)Sch[i].sum;
	}
	sort(Sch + 1, Sch + cnt, cmp);
	printf("%d\n", cnt - 1);
	int rank;
	Sch[0].tws = -1;
	for(int i = 1; i < cnt; i++) {
		if(Sch[i].tws != Sch[i - 1].tws) {
			rank = i;
		}
		cout << rank << " " << Sch[i].name << " " << Sch[i].tws << " " << Sch[i].ns << endl;
	}
	return 0;
}
