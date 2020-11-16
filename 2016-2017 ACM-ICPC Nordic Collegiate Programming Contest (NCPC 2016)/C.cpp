#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,ans,p[4],mask,dp[55][55];
char s[1000];
pii v[55],mt[55];

inline bool cmp(pii a,pii b)
{
	if(a.second!=b.second) return p[a.second]<p[b.second];
	if(mask&(1<<a.second)) return a.first<b.first;
	return a.first>b.first;
}

int solve()
{
	for(int i=0;i<=n;i++) dp[0][i]=dp[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(v[i-1]==mt[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	return n-dp[n][n];
}

int main()
{
	scanf("%d",&n);
	ans=n;
	for(int i=0;i<4;i++) p[i]=i+1;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		int x,y;
		if(s[0]>='2'&&s[0]<='9') x=s[0]-'1';
		else if(s[0]=='T') x=10;
		else if(s[0]=='J') x=11;
		else if(s[0]=='Q') x=12;
		else if(s[0]=='K') x=13;
		else if(s[0]=='A') x=14;
		if(s[1]=='s') y=0;
		else if(s[1]=='h') y=1;
		else if(s[1]=='d') y=2;
		else y=3;
		v[i]={x,y};
	}
	for(int i=0;i<n;i++) mt[i]=v[i];
	for(mask=0;mask<(1<<4);mask++)
	{
		do{
			sort(v,v+n,cmp);
			//for(int i=0;i<n;i++)
			//	printf("(%d,%d) ",v[i].first,v[i].second);
			//printf(": %d\n",solve());
			ans=min(ans,solve());
		}while(next_permutation(p,p+4));
	}
	printf("%d",ans);
	return 0;
}
