#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double num[105];
    double dp[105][2];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    dp[0][0]=100;//ÃÀÔª
    dp[0][1]=0;//Â¬²¼
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]/num[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]*num[i]);
    }
    printf("%.2lf",dp[n][0]);
    return 0;
}
