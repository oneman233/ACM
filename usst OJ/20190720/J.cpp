#include <bits/stdc++.h>
#define int long long
using namespace std;

int t,n;
int dp[40000][5];

signed main()
{
    scanf("%lld",&t);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i*i<=32768;++i){
        for(int j=i*i;j<=32768;++j){
            for(int k=1;k<=4;++k){
                dp[j][k]+=dp[j-i*i][k-1];
            }
        }
    }
    while(t--){
        scanf("%lld",&n);
        int ans=dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4];
        printf("%lld\n",ans);
    }
    return 0;
}
