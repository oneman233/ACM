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
using namespace std;
const int maxn=300000;
typedef long long ll;

ll jie(int x,int y)
{
    ll ans=1;
    re(i,y+1,x)
        ans*=i;
    if(y&1)
        return -ans;
    else
        return ans;
}

int main()
{
    int n;
    sci(n);
    ll ans=0;
    re(i,2,n)
        ans+=jie(n,i);
    prl(ans);
    return 0;
}
