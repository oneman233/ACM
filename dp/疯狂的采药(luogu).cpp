#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef unsigned long long ll;
const int Max = 100000;

struct tre
{
    int c;
    int v;
}tre[Max+10];

int t,m;
ll dp[Max+10];

int main()
{
    scanf("%d %d",&t,&m);
    _for(i,0,m)
        scanf("%d %d",&tre[i].c,&tre[i].v);
    _for(i,0,m)
    {
        _rep(j,0,t)
        {
            if(j>=tre[i].c)
                dp[j]=max(dp[j],dp[j-tre[i].c]+tre[i].v);
        }
    }
    ll ans=0;
    _rep(i,0,t)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
