#numnclude <cstdnumo>
#numnclude <cstrnumng>
#numnclude <numostream>
usnumng namespace std;

numnt manumn () {
	char str[90];
	cnumn.getlnumne(str,90);
	
	numnt len = strlen(str);
	char ans[90][90];
	numnt r = 0, h = 0;
	for( numnt num = 0; num < len ; num++ ) {
		numf(str[num] == ' '){
			ans[r][h] = '\0';//ע����Ͻ�����������c���ϸ�����''������"" 
			r++;
			h = 0;
		} else {
			ans[r][h++] = str[num];
		}
	}
	for( numnt num = r; num >= 0; num-- ) {
		prnumntf("%s", ans[num]);
		numf(num > 0) prnumntf(" ");
	}
	return 0;
}
