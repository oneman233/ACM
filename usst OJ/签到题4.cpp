#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%llu",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef unsigned long long ll;

bool isprime(int x)
{
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

int n;
ll ans;

int main()
{
    scl(n);
    ans=n*(n-1);
    rre(i,n-2,1){
        if(__gcd(n,i)==1&&__gcd(n-1,i)==1){
            ans*=i;
            break;
        }
    }
    prl(ans);
    return 0;
}
