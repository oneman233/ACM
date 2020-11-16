#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll n,k,dp[2505][2];
vector<int> e[2505];

ll dfs(int now,int fa,ll k)
{
	dp[now][0]=dp[now][1]=1;
	ll tmp=1;
	for(auto to:e[now])
	{
		if(to==fa) continue;
		dfs(to,now,k);
		tmp*=dp[to][1],tmp%=mod;
	}
	dp[now][0]*=tmp*k%mod,dp[now][0]%=mod;
	dp[now][1]*=tmp*(k-1)%mod,dp[now][1]%=mod;
	if(now==fa) return dp[now][0];
	return 0;
}

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1,x;i<n;i++)
	{
		scanf("%d",&x);
		e[i].push_back(x);
		e[x].push_back(i);
	}
	ll ans=dfs(0,0,k),qaq=1;
	for(int i=0,j=k-1;j>0;j--,i++)
	{
		qaq=qaq*(j+1)%mod;
		if(i&1) ans+=qaq*dfs(0,0,j)%mod;
		else ans-=qaq*dfs(0,0,j)%mod;
		ans=(ans+mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}
/*
4 3
0
1
1

6 4
0
1
1
3
4
*/
