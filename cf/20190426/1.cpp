#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef long long ll;

ll ans=1;
map<ll,int> m;

int main()
{
    ll n;
    scl(n);
    m[n]=1;
    while(++n)
    {
        while(n%10==0)
            n/=10;
        if(m[n]==0)
        {
            ans++;
            m[n]++;
        }
        else
            break;
    }
    pri(ans);
    return 0;
}
