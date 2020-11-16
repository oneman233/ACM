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
const int mod=99999;
typedef long long ll;

int n,b;
ll a[20005];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    scii(n,b);
    fo(i,0,n)
        scl(a[i]);
    sort(a,a+n,cmp);
    ll tmp=0;
    fo(i,0,n)
    {
        tmp+=a[i];
        if(tmp>=b){
            pri(i+1);
            break;
        }
    }
    return 0;
}
