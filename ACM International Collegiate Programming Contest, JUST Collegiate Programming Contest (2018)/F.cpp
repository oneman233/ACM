#include <bits/stdc++.h>
using namespace std;

int _,n,m;

int main()
{
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1;i<=n;++i){
			int a,b,c,d;
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			int s=a*60+b;
			int t=c*60+d;
			sum+=t-s;
		}
		if(sum/60>=m) puts("YES");
		else puts("NO");
	}
	return 0;
}
