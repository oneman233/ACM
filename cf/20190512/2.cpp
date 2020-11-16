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
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef long long ll;

int n,a[maxn+5],ans;

int main()
{
    sci(n);
    re(i,1,n)
        sci(a[i]);
    ans=min(a[1],a[n])/abs(1-n);
    re(i,2,n-1)
        ans=min(ans,min(min(a[i],a[1])/abs(i-1),min(a[i],a[n])/abs(i-n)));
    pri(ans);
    return 0;
}
