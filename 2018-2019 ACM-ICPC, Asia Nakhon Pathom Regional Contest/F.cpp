#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200;
const ll mod=1e9+7;
int c[555][555];
int ans[555];

void gao()
{
	c[1][1]=1;
	for(int i=2;i<=N;++i){
		c[i][1]=c[i][i]=1;
		for(int j=2;j<=i-1;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%7;//,printf("%c%c",c[i][j]==0?'0':' '," \n"[j==i-1]);
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=i;++j)
			if(c[i][j]%7==0)
				ans[i]++;
		//ans[i]+=ans[i-1];
	}
	for(int i=1;i<=N;++i)
		cout<<ans[i]<<" \n"[i%7==0];
}

ll qpow(ll a,ll b,ll m)
{
	a%=m;
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}

int Case=1,t;
ll n,inv=qpow(2ll,mod-2,mod);
void gao2()
{
	scanf("%lld",&n);
	ll cnt=n/7;
	if(cnt==0) return printf("Case %d: 0\n",Case),void(0);
	cnt--;
	ll ans=(cnt+1)%mod*21%mod*(cnt%mod)%mod*inv%mod;
	ll rem=n%7;
	if(rem==6) rem=5;
	rem++;cnt++;
	ll tmp=(13-rem+mod)%mod*(cnt%mod)%mod*rem%mod*inv%mod;
	printf("Case %d: %lld\n",Case,ans);
	ans=(ans+tmp)%mod;
	printf("Case %d: %lld\n",Case,ans);
}


int main()
{
	gao();
	scanf("%d",&t);
	for(;Case<=t;++Case) gao2();
	return 0;
}
