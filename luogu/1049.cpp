#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int Max = 100000;

int main()
{
    int bag,n,dp[Max],c[Max];
    cin>>bag;
    cin>>n;
    _for(i,0,n)
        cin>>c[i];
    _for(i,0,n)
    {
        for(int j=bag;j>=c[i];--j)
        {
            dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
        }
    }
    int ans=0;
    _rep(i,0,bag)
        ans=max(ans,dp[i]);
    cout<<bag-ans;
    return 0;
}
