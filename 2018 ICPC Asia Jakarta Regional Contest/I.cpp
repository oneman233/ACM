#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5;
char s[MN];

int main(){
	int n; scanf("%d",&n);
	int cntL=0;
	for(int i=0; i<n; ++i){
		scanf("%s",s);
		if(s[0]=='L') ++cntL;
	}
	puts((cntL&1)? "LIE": "TRUTH");
	return 0;
}
