#include <bits/stdc++.h>
using namespace std;

int n;

void gao()
{
	int ans=0,last=-1e5;
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)
	{
		scanf("%d",&x);
		if(x>last+20) last=x,ans++;
	}
	printf("%d\n",ans);
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--) gao();
	return 0;
}
/*
2
5
1 2 3 200 210
4
10 30 80 200
*/
