#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int fish[105];
    int dp[105];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>fish[i];
    for(int i=0;i<n;i++)
        dp[i]=0;
    for(int i=1;i<n;i++)
    {
        if(fish[i]>fish[i-1])
            dp[i]=max(dp[i-1]+1,dp[i]);
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";
    return 0;
}
