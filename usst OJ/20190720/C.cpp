#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[105][105];
int dp[105];

signed main()
{
    while(~scanf("%lld %lld",&n,&m)){
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%lld",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i){
            for(int j=m;j>=1;--j){
                for(int k=1;k<=j;++k){
                    dp[j]=max(dp[j],dp[j-k]+a[i][k]);
                }
            }
        }
        printf("%lld\n",dp[m]);
    }
    return 0;
}
