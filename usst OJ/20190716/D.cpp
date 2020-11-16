#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

ll t;
ll l,r,k;

signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&l,&r,&k);
        if(k&1)
            printf("%lld\n",r-l+1);
        else
            printf("%lld\n",r-l+1-((r+1)/(k+1))+(l/(k+1)));
    }
    return 0;
}
