#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef unsigned long long ll;
const int Max = 100000;

struct num
{
    int p;
    int v;
}num[Max];

int main()
{
    int n,m;
    ll dp[Max];
    scanf("%d %d",&n,&m);
    _for(i,0,m)
        scanf("%d %d",&num[i].p,&num[i].v);
    _for(i,0,m)
    {
        for(int j=n;j>=0;j--)
        {
            if(j>=num[i].p)
                dp[j]=max(dp[j],dp[j-num[i].p]+num[i].v*num[i].p);
        }
    }
    ll ans=0;
    _rep(i,0,n)
        ans=max(dp[i],ans);
    cout<<ans;
    return 0;
}
