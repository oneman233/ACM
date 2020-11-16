#include <bits/stdc++.h>
using namespace std;

int n,m;
int p[1005][1005];
int dp[1005][1005];

int mmin(int a,int b,int c)
{
    return min(a,min(b,c));
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(p[i][j]==1){
                dp[i][j]=mmin(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                dp[i][j]=max(dp[i][j],1);
            }
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ans=max(ans,dp[i][j]);
    printf("%d",ans);
    return 0;
}
