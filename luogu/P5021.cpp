#include <bits/stdc++.h>
using namespace std;
const int N=50005;

int n,m;
vector<pair<int,int>> e[N];

bool ok(int now)
{
	
}

int half(int l,int r)
{
	while(l<=r)
	{
		int m=(l+r)/2;
		if(ok(m)) l=m+1;
		else r=m-1;
	}
	return 
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i,x,y,z;i<=n-1;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		e[x].emplace_back(y,z);
		e[y].emplace_back(x,z);
	}
	int ans=half(1,5e8);
	printf("%d",ans);
	return 0;
}
