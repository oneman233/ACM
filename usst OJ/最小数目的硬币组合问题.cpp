#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum,a[100];
    int dp[10000];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    cin>>sum;
    for(int i=1;i<=sum;++i)
        dp[i]=10000;
    for(int i=0;i<n;++i)
    {
        for(int j=a[i];j<=sum;++j)
        {
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[sum];
    return 0;
}
