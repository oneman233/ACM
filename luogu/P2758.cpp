#include <bits/stdc++.h>
using namespace std;

string a,b;
int ans=0,la,lb,dp[2005][2005];

void work()
{
    la=a.length();
    lb=b.length();
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=lb;++i)
        dp[0][i]=i;
    for(int i=0;i<=la;++i)
        dp[i][0]=i;
    for(int i=1;i<=la;++i){
        for(int j=1;j<=lb;++j){
            if(a[i-1]==b[j-1])
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            else
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    cout<<dp[la][lb];
}

int main()
{
    cin>>a>>b;
    work();
    return 0;
}
/*
fxpimu
xwrs
*/
