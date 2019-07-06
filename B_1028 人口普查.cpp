#include <cstdio>
#include <cstring>
struct people {
	char name[20];
	int yyyy;
	int mm;
	int dd;;
}youngest,oldest,min,max,person;
void init(){
	oldest.yyyy = max.yyyy = 2014;
	oldest.mm = max.mm = 9;
	oldest.dd =max.dd = 6;
	youngest.yyyy = min.yyyy = 1814;
	youngest.mm = min.mm = 9;
	youngest.dd = min.dd = 6;
}
bool less(people a, people b) {//如果a 小于 b，返回true 
	if( a.yyyy != b.yyyy) return a.yyyy <= b.yyyy;
	else if( a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd;
}
bool more(people a, people b) {//如果大于 b，返回true 
	if( a.yyyy != b.yyyy) return a.yyyy >= b.yyyy;
	else if( a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd;
}


int main() {
	init();//记得初始化 
	int n,count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", person.name, &person.yyyy, &person.mm, &person.dd);
		if(less(person, max) && more(person, min)) {//日期有效 
			count++;
			if(less(person,oldest)) oldest = person;
			if(more(person,youngest)) youngest = person;
		}
	}
	if(count == 0) printf("0\n");
	else printf("%d %s %s\n", count, oldest.name, youngest.name);
	return 0;
}
