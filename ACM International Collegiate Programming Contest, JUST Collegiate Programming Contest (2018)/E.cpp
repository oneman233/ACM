#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a[20][20],dp[17][1<<16];
vector<int> s,v[1<<16];

void solve()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<=n;i++)
		for(auto p:s) 
			if(p<(1<<n)) dp[i][p]=0;
	for(int i=1;i<=n;i++)
	{
		for(auto p:s)
		{
			if(p>=(1<<n)) continue;
			for(auto to:v[p])
			{
				if(to>=(1<<n)) continue;
				int sum=0;
				for(int j=0;j<n;j++)
					if(to&(1<<j)) sum+=a[i][j];
				dp[i][to]=max(dp[i][to],dp[i-1][p]+sum);
				ans=max(ans,dp[i][to]);
			}
		}
	}
	printf("%d\n",ans);
}

inline bool check(int x,int y)
{
	if(x&y) return false;
	if(x&(y<<1)) return false;
	if(x&(y>>1)) return false;
	return true;
}

void init(int n)
{
	for(int i=0;i<(1<<n);i++)
	{
		vector<int> vs;
		int flag=0;
		for(int j=1;j<n;j++)
			if(i&(1<<j))
				if(i&(1<<(j-1))) 
				{
					flag=1;
					break;
				}
		if(!flag) s.push_back(i);
	}
	for(auto p:s)
		for(auto to:s)
			if(check(p,to)) v[p].push_back(to);
}

int main()
{
	//freopen("e.in","r",stdin);
	//freopen("e.out","w",stdout);
	init(16); 
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}

/*
2
2
4 7
2 9
3
1 2 3
4 5 6
7 8 9
*/
