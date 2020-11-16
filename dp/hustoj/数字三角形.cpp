#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int a[100][100];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                cin>>a[i][j];
            }
        }
        int dp[100][100];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                dp[i][j]=a[i][j];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=max(dp[i][j],max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]));
            }
        }
        int big=0;
        for(int i=1;i<=n;++i)
            big=max(big,dp[n][i]);
        cout<<big<<endl;
    }
    return 0;
}
