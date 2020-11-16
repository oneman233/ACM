#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[110],dp[110][110];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            dp[i][j]=abs(a[i]-a[j])*(j-i+1);
            for(int k=i;k<=j;++k)
            {
                dp[i][j]=max(dp[i][j],dp[i][k-1]+abs(a[k]-a[j])*(j-k+1));
                dp[i][j]=max(dp[i][j],dp[k+1][j]+abs(a[i]-a[k])*(k-i+1));
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
