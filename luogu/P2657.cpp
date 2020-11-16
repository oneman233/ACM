#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=25;

ll a,b;
int dp[N][N],num[N];

int dfs(int len,int last,int up)
//from right to right
{
	if(len==0) return 1;
	if(!up&&last>=0&&dp[len][last]!=-1)
		return dp[len][last];
	int p,cnt=0,mx=(up?num[len]:9);
	for(int i=0;i<=mx;++i)
	{
		if(abs(i-last)<2) continue;
		if(i==0&&last==-2) p=-2;
		else p=i;
		cnt+=dfs(len-1,p,up&&i==mx);
	}
	if(!up&&last>=0) dp[len][last]=cnt;
	return cnt;
}

void gao()
{
	int k=0;
	a--;
	while(a)
	{
		num[++k]=a%10;
		//start from 1
		a/=10;
	}
	memset(dp,-1,sizeof(dp));
	int left=dfs(k,-2,1);
	k=0;
	while(b)
	{
		num[++k]=b%10;
		b/=10;
	}
	memset(dp,-1,sizeof(dp));
	int right=dfs(k,-2,1);
	//last should be at most -2
	//because we need 0 1 2... to be legal
	printf("%d\n",right-left);
}

int main()
{
	scanf("%lld%lld",&a,&b);
	gao();
	return 0;
}
