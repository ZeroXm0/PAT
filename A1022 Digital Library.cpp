#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
map<string, set<int> > title, author, thekey, publisher, year;
void query(map<string, set<int> > &library, string &temp) {
	if(library.find(temp) == library.end()) printf("Not Found\n");
	else {
		for(set<int>::iterator it = library[temp].begin(); it != library[temp].end(); it++) {
		    printf("%07d\n", *it);      //此处用printf，才能输出保证是7位编号
		}
	}
}
int main() {
	int n, m;
	scanf("%d", &n);
	while(n--) {
		int id;
		scanf("%d", &id);
		getchar();
		string str1;
		getline(cin, str1);
		title[str1].insert(id);
		getline(cin, str1);
		author[str1].insert(id);
		while(cin >> str1) {
			thekey[str1].insert(id);
		    char c = getchar();
			if(c == '\n') break;
		}
		getline(cin, str1);
		publisher[str1].insert(id);
		getline(cin, str1);
		year[str1].insert(id);
	}
	string temp;
	scanf("%d", &m);
	while(m--) {
		int type;
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		if(type == 1) query(title, temp);
		else if(type == 2) query(author, temp);
		else if(type == 3) query(thekey, temp);
		else if(type == 4) query(publisher, temp);
		else query(year, temp);
	}
	return 0;
} 
