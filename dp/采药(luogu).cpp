#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,m;
    cin>>t>>m;
    int cos[1005],val[1005];
    int dp[1005];
    for(int i=0;i<m;++i)
        cin>>cos[i]>>val[i];
    for(int i=0;i<m;++i)
    {
        for(int j=t;j>=0;--j)
        {
            if(j>=cos[i])
                dp[j] = max(dp[j], dp[j-cos[i]]+val[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=t;++i)
        ans = max(ans, dp[i]);
    cout<<ans;
    return 0;
}
