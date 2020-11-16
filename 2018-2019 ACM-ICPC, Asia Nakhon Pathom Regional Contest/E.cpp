#include <bits/stdc++.h>
using namespace std;

int t,n,a[105],Case=1;
int dp[105][7];

void gao()
{
	memset(dp,0,sizeof(dp));
	int ans=1;
	for(int i=1;i<=n;++i) for(int j=0;j<3;++j) dp[i][j]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j){
			if(abs(a[i]-a[j])<=2) dp[i][0]=max(dp[i][0],dp[j][0]+1);
			if(abs(a[i]+1-a[j])<=2) dp[i][1]=max(dp[i][1],dp[j][0]+1);
			if(abs(a[i]-1-a[j])<=2) dp[i][2]=max(dp[i][2],dp[j][0]+1);
			if(abs(a[i]-(a[j]+1))<=2) dp[i][3]=max(dp[i][3],dp[j][1]+1);
			if(abs(a[i]-(a[j]-1))<=2) dp[i][3]=max(dp[i][3],dp[j][2]+1);
			if(abs(a[i]-a[j])<=2) dp[i][3]=max(dp[i][3],dp[j][3]+1);
			if(abs(a[i]+1-a[j])<=2)
				dp[i][4]=max(dp[i][4],dp[j][3]+1);
			if(abs(a[i]-1-a[j])<=2)
				dp[i][5]=max(dp[i][5],dp[j][3]+1);
			if(abs(a[i]+1-(a[j]+1))<=2)
				dp[i][4]=max(dp[i][4],dp[j][1]+1);
			if(abs(a[i]+1-(a[j]-1))<=2)
				dp[i][4]=max(dp[i][4],dp[j][2]+1);
			if(abs(a[i]-1-(a[j]+1))<=2)
				dp[i][5]=max(dp[i][5],dp[j][1]+1);
			if(abs(a[i]-1-(a[j]-1))<=2)
				dp[i][5]=max(dp[i][5],dp[j][2]+1);
			if(abs(a[i]-(a[j]+1))<=2) dp[i][6]=max(dp[i][6],dp[j][4]+1);
			if(abs(a[i]-(a[j]-1))<=2) dp[i][6]=max(dp[i][6],dp[j][5]+1);
			if(abs(a[i]-a[j])<=2) dp[i][6]=max(dp[i][6],dp[j][6]+1);
		}
		for(int j=0;j<7;++j) ans=max(ans,dp[i][j]);
	}
	printf("Case %d: %d\n",Case,ans);
}

int main()
{
	scanf("%d",&t);
	for(;Case<=t;++Case)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		gao();
	}
	return 0;
}
/*
6
10
2 1 7 4 3 8 9 12 13 20
3
1 2 3
4
1 2 7 8
3
10 30 20
2
5 5
5
1 2 9 10 13
*/
