#include<bits/stdc++.h>
using namespace std;

int n;
int dp[2010][2010],a[2010];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[i][i]=a[i]*n;///第n天的时候拿他
    }
    for(int l=2;l<=n;++l)
    {
        for(int i=1;(i+l-1)<=n;++i)
        {
            int j=i+l-1;
            dp[i][j]=max(dp[i+1][j]+a[i]*(n-l+1),dp[i][j-1]+a[j]*(n-l+1));
        }
    }
    ///l代表的是区间上有几个点
    ///n-l代表除去该区间外剩下几个点
    ///时间从1开始，其余点全部取完时候时间来到了1+n-l
    cout<<dp[1][n];
    return 0;
}
