#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int r,s,n,d,m;
bool gg[111][111];
ll b[1005],ans;
vector<int>in[111];
ll qmul(ll a,ll b)
{
	ll ans=0;
	for(;b;b>>=1,a=a+a)
		if(b&1)
		{
			ans=ans+a;
			if(ans>1e18)
				printf("too many"),exit(0);
		}
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d",&r,&s,&m,&d,&n);
	for(int i=1;i<=r;i++)scanf("%lld",b+i);
	for(int i=1,t,tt;i<=s+m+d;i++){scanf("%d",&t);while(t--)scanf("%d",&tt),in[i].push_back(tt);}
	for(int i=1,u,v;i<=n;i++)scanf("%d%d",&u,&v),gg[u][v]=gg[v][u]=1;
	for(int i=1;i<=s;i++)
		for(int j=s+1;j<=s+m;j++)
			for(int k=s+m+1;k<=s+m+d;k++)
				if(!gg[i][j]&&!gg[i][k]&&!gg[j][k])
				{
					set<int>s;
					for(auto t:in[i])s.insert(t);
					for(auto t:in[j])s.insert(t);
					for(auto t:in[k])s.insert(t);
					ll tt=1;
					for(auto t:s)
						tt=qmul(tt,b[t]);
					ans+=tt;
					if(ans>1e18)
						return !printf("too many");
				}
	printf("%lld\n",ans);
	return 0;
}
