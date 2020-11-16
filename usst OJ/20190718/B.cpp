#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1000000007;

int n,m;
int c[1005][1005];
int s[1005];

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    c[0][0]=1;
    for(int i=1;i<=1000;++i)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;++j)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
            c[i][j]%=mod;
        }
    }
    sort(s+1,s+1+n);
    int ans=0;
    for(int i=1;i<n;++i){
        ans+=(s[i]*c[n-i][m-1])%mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
