#include <bits/stdc++.h>
using namespace std;

int _,n,p[25];

int main()
{
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&p[i]);
		int ans=0;
		for(int i=1;i<=n;++i) if(p[i]!=0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
5 7 2 1
3
1 0 1
5
4 0 1 0 3
*/
