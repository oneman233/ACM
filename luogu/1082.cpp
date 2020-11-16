#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y;

void exgcd(ll a,ll b)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    else
    {
        exgcd(b,a%b);
        ll tx=x,ty=y;
        x=ty;
        y=tx-a/b*ty;
    }
}

int main()
{
    ll a,b;
    cin>>a>>b;
    exgcd(a,b);
    while(x<0) x+=b;
    x%=b;
    cout<<x;
    return 0;
}
