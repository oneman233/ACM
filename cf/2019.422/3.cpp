#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
const int Max=300000;

int n,m;
ll x[Max+5],y[Max+5];
ll p[Max+5];

int main()
{
    scanf("%d %d",&n,&m);
    re(i,1,n)
        scanf("%lld",&x[i]);
    re(i,1,m)
        scanf("%lld",&p[i]);
    for(int i=1;i<=n-1;++i)
        y[i]=x[i+1]-x[i];
    ll gcd=y[1];
    for(int i=2;i<=n-1;++i)
    {
        gcd=__gcd(gcd,y[i]);
        if(gcd==1)
            break;
    }
    ///cout<<gcd;
    bool can=false;
    int ans;
    for(int i=1;i<=m;++i)
    {
        if(p[i]==gcd||gcd%p[i]==0)
        {
            can=true;
            ans=i;
            break;
        }
    }
    if(can)
    {
        cout<<"YES"<<endl;
        cout<<x[1]<<" "<<ans;
    }
    else
        cout<<"NO";
    return 0;
}
