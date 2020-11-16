#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s,a,b;
    int x[5005],y[5005];
    cin>>n>>s;
    cin>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];//空一行便于控制后面的i-1
    int dp[5005][1005];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)//遍历苹果编号
    {
        for(int j=0;j<=s;j++)//遍历力气消耗
        {
            dp[i][j]=dp[i-1][j];//至少是这么多
            if(j>=y[i]&&x[i]<=a+b)//高度够并且消耗够
                dp[i][j]=max(dp[i][j],dp[i-1][j-y[i]]+1);
        }
    }
    cout<<dp[n][s];
    return 0;
}
