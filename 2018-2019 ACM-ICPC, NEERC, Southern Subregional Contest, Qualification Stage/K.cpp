#include <bits/stdc++.h>
using namespace std;

int n,m,a[5005];
int cnt[5005][5005];
int dp[5005];

priority_queue<int> q_big;
priority_queue<int,vector<int>,greater<int>> q_small;

void gao()
{
	for(int i=1;i<=n;++i)
	{
		while(!q_small.empty()) q_small.pop();
		while(!q_big.empty()) q_big.pop();
   	 	q_big.push(-2000000001);
   	 	q_small.push(2000000001);
		for(int j=i;j<=n;++j)
		{
			//a[j]
			if(a[j]<q_big.top())
	        {
	            q_small.push(q_big.top());
	            q_big.pop();
	            q_big.push(a[j]);
	        }
	        else
            	q_small.push(a[j]);
            printf("! %d %d\n",q_big.size(),q_small.size());
			cnt[i][j]=q_big.top();
		}
	}
}

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
			if(cnt[j+1][i]>=m) dp[i]=max(dp[i],dp[j]+1);
	printf("%d",dp[n]<0?0:dp[n]);
	return 0;
}
/*
5 2
10 3 2 3 2
*/
