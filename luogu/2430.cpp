#include <bits/stdc++.h>
using namespace std;

int a,b,p,q;
int m,n;
int tim;
int c[10000],val[10000],dp[10000],cost[10000];

int main()
{
    memset(cost,0,sizeof(cost));
    memset(dp,0,sizeof(dp));
    memset(val,0,sizeof(val));
    cin>>a>>b;
    cin>>m>>n;
    for(int i=1;i<=n;++i)
        cin>>c[i];
    for(int i=0;i<m;++i)
    {
        cin>>p>>q;
        cost[i]=c[p];
        val[i]=q;
    }
    cin>>tim;
    tim/=(b/a);
    for(int i=0;i<m;++i)
    {
        for(int j=tim;j>=cost[i];--j)
        {
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
        }
    }
    int ans=-100;
    for(int i=0;i<=tim;++i)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
