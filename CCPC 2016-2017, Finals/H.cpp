#include <bits/stdc++.h>
using namespace std;

int _,n,m,dp[15][1<<11];
vector<int> task[15],ab[15];
set<int> can[15];

void solve(int Case)
{
	int ans=0;
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)
	{
		can[i].clear();
		task[i].clear();
		scanf("%d",&x);
		for(int j=0,y;j<x;j++) scanf("%d",&y),task[i].push_back(y);
	}
	for(int i=0,x;i<m;i++)
	{
		ab[i].clear();
		scanf("%d",&x);
		for(int j=0,y;j<x;j++) scanf("%d",&y),ab[i].push_back(y);
	}
	for(int i=0;i<(1<<m);i++)
	{
		set<int> tmp;tmp.clear();
		for(int j=0;j<m;j++)
			if((i>>j)&1) 
				for(auto p:ab[j]) tmp.insert(p);
		for(int j=1;j<=n;j++)
		{
			int flag=1;
			for(auto p:task[j]) if(!tmp.count(p)) {flag=0;break;}
			if(flag) can[j].insert(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int msk=0;msk<(1<<m);msk++)
		{
			dp[i][msk]=max(dp[i][msk],dp[i-1][msk]);
    		for(int s=msk;s;s=(s-1)&msk)
    			if(can[i].count(s)) 
					dp[i][msk]=max(dp[i][msk],dp[i-1][msk-s]+1),
					ans=max(ans,dp[i][msk]);
		}
	printf("Case #%d: %d\n",Case,ans);
}

int main()
{
	scanf("%d",&_);
	for(int Case=1;Case<=_;++Case) solve(Case);
	return 0;
}

/*
100
1 1
1 1
1 1


100
2 6
3 1 2 3 
3 1 2 3
1 1
1 1
1 2
1 2
1 3
1 3

3 4
3 40 77 64
3 10 40 20
3 40 20 77
2 40 77
2 77 64
2 40 10
2 20 77

2 4
3 1 2 3
3 2 3 4
2 1 2
2 2 3
2 2 3
1 4
*/
