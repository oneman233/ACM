#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max=500000;

int p,n;
int val[Max+5],pri[Max+5];
int dp[Max];

int main()
{
    cin>>p>>n;
    _for(i,0,n)
        cin>>val[i]>>pri[i];
    _for(i,0,n)
    {
        _rep(j,0,p)
        {
            if(j>=pri[i])
                dp[j]=max(dp[j],dp[j-pri[i]]+val[i]);
        }
    }
    int ans=0;
    _rep(i,0,p)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
