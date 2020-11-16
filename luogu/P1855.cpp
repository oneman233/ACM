#include <bits/stdc++.h>
using namespace std;

int n,m,t;
int a[105],b[105];
int dp[1000][1000];

int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>t;
    for(int i=0;i<n;++i)
        cin>>a[i]>>b[i];
    for(int i=0;i<n;++i){
        for(int j=m;j>=a[i];j--){
            for(int k=t;k>=b[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-a[i]][k-b[i]]+1);
            }
        }
    }
    cout<<dp[m][t];
    return 0;
}
