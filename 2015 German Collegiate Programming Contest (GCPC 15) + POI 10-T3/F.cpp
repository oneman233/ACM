#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define elif else if

ll n;
const int times=10;
const int N=5500;
ll ct,cnt;
ll fac[N],num[N];

ll multi(ll a ,ll b,ll m)
{
    ll ans=0;a%=m;
    while(b)
    {
        if(b&1){
            ans=(ans+a)%m;
            b--;

        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}

ll quickmod(ll a,ll b,ll m)
{
    ll ans=1;
    a%=m;
    while(b)
    {
        if(b&1){
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
bool Miller(ll n)
{
    if(n==2)return true;
    if(n<2||!(n&1))return false;
    ll m=n-1;
    int k=0;
    while((m&1)==0)
    {
        k++;
        m>>=1;
    }
    for(int i=0;i<times;++i)
    {
        ll a=rand()%(n-1)+1;
        ll x=quickmod(a,m,n);
        ll y=0;
        for(int j=0;j<k;++j)
        {
            y=multi(x,x,n);
            if(y==1&&x!=1&&x!=n-1)return false;
            x=y;
        }
        if(y!=1)return false;
    }
    return true;
}

ll pollard(ll n ,ll c)
{
    ll i=1,k=2;
    ll x=rand()%(n-1)+1;
    ll y=x;
    while(true)
    {
        i++;
        x=(multi(x,x,n)+c)%n;
        ll d=__gcd((y-x+n)%n,n);
        if(1<d&&d<n)return d;
        if(y==x)return n;
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}

void find(ll n,ll c)
{
    if(n==1)return;
    if(Miller(n)){
        fac[ct++]=n;
        return;
    }
    ll p=n;
    ll k=c;
    while(p>=n)p=pollard(p,c--);
    find(p,k);
    find(n/p,k);
}
int main()
{
    scanf("%lld",&n);
    if(n==1) return puts("1"),0;
    ct=0;
    find(n,120);
    sort(fac,fac+ct);
    num[0]=1;
    int k=1;
    for(int i=1;i<ct;++i)
    {
        if(fac[i]==fac[i-1])++num[k-1];
        else {
            num[k]=1;
            fac[k++]=fac[i];
        }
    }
    cnt=k;
    ll ans=1;
    for(int i=0;i<cnt;++i) {
        ans *= (num[i] + 1);

//        cout<<fac[i]<<" "<<num[i]<<endl;
    }
    cout<<ans<<endl;
}
