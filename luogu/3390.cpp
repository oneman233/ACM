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
#define prs()  printf(" ")
using namespace std;
const int maxn=100;
typedef long long ll;
const ll mod=1000000007;

int n;
ll k;
struct matrix
{
    ll a[maxn+5][maxn+5];
    void put()
    {
        re(i,1,n)
        {
            re(j,1,n)
            {
                prl(a[i][j]);
                if(j!=n)
                    prs();
            }
            if(i!=n)
                prn();
        }
    }
}m;

matrix mul(matrix a,matrix b)
{
    matrix c;
    memset(c.a,0,sizeof(c.a));
    re(i,1,n)
    {
        re(j,1,n)
        {
            re(k,1,n)
            {
                c.a[i][j]+=((a.a[i][k]%mod)*(b.a[k][j]%mod))%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}

void qpow()
{
    matrix ans;
    memset(ans.a,0,sizeof(ans.a));
    re(i,1,n)
        ans.a[i][i]=1;
    while(k)
    {
        if(k&1)
            ans=mul(ans,m);
        m=mul(m,m);
        k>>=1;
    }
    ans.put();
}

int main()
{
    ll tmp;
    sci(n);
    scl(k);
    re(i,1,n)
        re(j,1,n)
            scl(tmp),m.a[i][j]=tmp%mod;
    qpow();
    return 0;
}
