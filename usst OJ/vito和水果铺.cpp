#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num[100005];
    long long dp[100005];
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    memset(dp,0,sizeof(dp));
    dp[0]=num[0];
    dp[1]=num[1];
    for(int i=0;i<n;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            dp[j]=max(dp[j],dp[i]+num[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i]>ans)
            ans=dp[i];
    }
    cout<<ans;
    return 0;
}
