#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    long long lose[1005],win[1005];
    int use[1005];
    long long dp[1005];
    cin>>n>>x;
    for(int i=0;i<n;++i)
        cin>>lose[i]>>win[i]>>use[i];
    for(int i=0;i<n;++i)
    {
        for(int j=x;j>=use[i];j--)
            dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
        for(int j=use[i]-1;j>=0;j--)
            dp[j]+=lose[i];
    }
    long long ans=0;
    for(int i=0;i<=x;++i)
        ans=max(ans,dp[i]);
    cout<<ans*5;
    return 0;
}
