#include <bits/stdc++.h>
using namespace std;
const int maxm=10000;

int m,t;
long long c[maxm+5],v[maxm+5];
long long dp[100005];

int main()
{
    cin>>m>>t;
    for(int i=0;i<m;++i)
        cin>>c[i]>>v[i];
    for(int i=0;i<m;++i)
        for(int j=c[i];j<=t;j++)
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
    cout<<dp[t];
    return 0;
}
