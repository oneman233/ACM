#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000007;

int main()
{
    ll n,m,a[105];
    ll dp[105][105];
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        dp[i][0]=1;
        for(int j=1;j<=m;++j){
            for(int k=0;k<=a[i]&&j-k>=0;++k){
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
