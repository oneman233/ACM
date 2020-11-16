#include <bits/stdc++.h>
using namespace std;

int a[100010][11],dp[100010][11];

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int T=0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            int t,x;
            scanf("%d %d",&x,&t);
            a[t][x]++;
            T=max(T,t);
        }
        for(int i=T;i>=0;--i)///时间是倒序向前
        {
            for(int j=0;j<=10;++j)
            {
                if(j==0)
                    dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
                else if(j==10)
                    dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1-1][j]+a[i][j]);
                else
                    dp[i][j]=max(dp[i+1][j]+a[i][j],max(dp[i+1][j-1],dp[i+1][j+1])+a[i][j]);
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}
