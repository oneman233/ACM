#include <bits/stdc++.h>
using namespace std;

int n,m,a[5005];
bitset<5005> cnt[5005];
int dp[5005];

priority_queue<int> mxq[5005];
priority_queue<int,vector<int>,greater<int>> mnq[5005];

void gao()
{
	for(int i=1;i<=n;++i)
	{
//		while(!mxq.empty()) mxq.pop();
//		while(!mnq.empty()) mnq.pop();
		auto &mxq=::mxq[i];
		auto &mnq=::mnq[i];
		for(int j=i;j<=n;++j)
		{
			//a[j]
			mxq.push(a[j]);
			while(mxq.size()>(j-i+2)/2) mnq.push(mxq.top()),mxq.pop();
			while(!mnq.empty()&&mnq.top()<mxq.top()) 
			{
				mxq.push(mnq.top());
				mnq.pop();
				mnq.push(mxq.top());
				mxq.pop();
			}
			cnt[i][j]=mxq.top()>=m;
		}
	}
}

//shit!

int main()
{
	//freopen("k.in","r",stdin);
	//freopen("k.in","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	gao();
	//for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) cout<<cnt[i][j]<<" \n"[j==n];
	memset(dp,0xc0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(cnt[j+1][i]) dp[i]=max(dp[i],dp[j]+1);
	printf("%d",dp[n]<0?0:dp[n]);
	return 0;
}
/*
5 2
10 3 2 3 2
*/
