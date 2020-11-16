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
using namespace std;
const int maxn=300000;
typedef long long ll;

struct bigint
{
    vector<ll> v;
    bigint(ll n)
    {
        v.pb(n);///
    }
    bigint()
    {
        v.clear();
    }
    int cnt(ll n)
    {
        int ans=0;
        fo(i,0,v.size())
            if(v[i]==n)
                ++ans;
        return ans;
    }
    void put()
    {
        fo(i,0,v.size())
            pri(v[i]);
        ///prn();
    }
};

bigint add(bigint a,bigint b)
{
    bigint c;
    while(a.v.size()<b.v.size())
        a.v.insert(a.v.begin(),0LL);
    while(b.v.size()<a.v.size())
        b.v.insert(b.v.begin(),0LL);
    int len=a.v.size();
    fo(i,0,len)
        c.v.pb(a.v[i]+b.v[i]);///
    for(int i=len-1;i>=1;--i)
    {
        if(c.v[i]>=10)
        {
            c.v[i-1]+=c.v[i]/10;
            c.v[i]%=10;
        }
    }
    if(c.v[0]>=10)
    {
        ll tmp=c.v[0]/10;
        c.v[0]%=10;
        c.v.insert(c.v.begin(),tmp);
    }
    return c;
}

bigint mul(bigint a,ll b)
{
    bigint c;
    re(i,0,a.v.size()-1)
        c.v.pb(a.v[i]*b);///
    for(int i=c.v.size()-1;i>=1;--i)
    {
        if(c.v[i]>=10)
        {
            c.v[i-1]+=c.v[i]/10;
            c.v[i]%=10;
        }
    }
    if(c.v[0]>=10)
    {
        ll tmp=c.v[0]/10;
        c.v[0]%=10;
        ///c.v.insert(c.v.begin(),tmp);
        while(tmp)
        {
            c.v.insert(c.v.begin(),tmp%10);
            tmp/=10;
        }
    }
    return c;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n>>a;
        bigint jie(n);
        for(int i=n-1;i>=2;--i)
            jie=mul(jie,i);
        jie.put();
        ///cout<<jie.cnt(a)<<endl;
    }
    return 0;
}
