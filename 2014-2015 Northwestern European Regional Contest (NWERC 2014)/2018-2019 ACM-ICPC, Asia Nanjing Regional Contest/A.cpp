#include <bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if(n==0){
		puts("Austin");
		return 0;
	}
	if(n==1){
		puts("Adrien");
		return 0;
	}
	if(k==1){
		if(n&1) puts("Adrien");
		else puts("Austin");
		return 0;
	}
	puts("Adrien");
	return 0;
}
