#include <bits/stdc++.h>
using namespace std;

int n,m,s;
int dp[305][505];
int c[305],v[305];

int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<n;++i)
        cin>>c[i]>>v[i];
    for(int i=0;i<n;++i){
        for(int j=m;j>=1;--j){
            for(int k=s;k>=0;--k){
                if(k>=c[i])
                    dp[j][k]=max(dp[j][k],dp[j-1][k-c[i]]+v[i]);
                else
                    dp[j][k]=max(dp[j][k],dp[j-1][k]);
            }
        }
    }
    cout<<dp[m][s];
    return 0;
}
