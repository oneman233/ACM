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

inline ll read()
{
    char ch=getchar();
    ll x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch^48;
        ch=getchar();
    }
    return x*f;
}

int t;
ll x;
map<ll,int> m;

int main()
{
    sci(t);
    for(ll i=1;i<=100000;++i)
        m[1+i*(i-1)/2]++;
    while(t--){
        scl(x);
        if(m[x])
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
