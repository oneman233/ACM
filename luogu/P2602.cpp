#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=25;

ll a,b;
int num[N];
int dp[N][N][2][2];

ll gao2(int digit,int len,ll sum,bool zero,bool small)
{
	ll ret=0;
	if(len==0) return sum;
	if(dp[len][sum][zero][small]!=-1) return dp[len][sum][zero][small];
	for(int i=0;i<10;++i)
	{
		if(!small&&i>num[len]) break;
		ret+=gao2(digit,len-1,sum+((!zero||i)&&i==digit),zero&&i==0,small||(i<num[len]));
	}
	dp[len][sum][zero][small]=ret;
	return ret;
}

ll gao(ll x,int digit)
{
	int len=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return gao2(digit,len,0,1,0);
}

signed main()
{
	scanf("%lld%lld",&a,&b);
	for(int i=0;i<10;++i)
		printf("%lld ",gao(b,i)-gao(a-1,i));
	return 0;
}
