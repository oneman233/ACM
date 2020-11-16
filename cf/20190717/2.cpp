#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
#define debug(a) cout<<a<<endl
#define int long long
using namespace std;
typedef long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

ll n,k;
ll sum[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    if(k==0){
        int ans=0,flag=1;
        /*
        while(n){
            n-=1+flag;
            ans+=flag;
            flag++;
        }
        */
        int a=1;
        int cnt=(sqrt(4*a*a+8*n)-2*a)/2;
        ans+=n-cnt;
        cout<<ans;
        return 0;
    }
    sum[0]=0;
    for(int i=1;i<=500000;++i)
        sum[i]=sum[i-1]+i;
    int pos=lower_bound(sum,sum+500001,k)-sum;
    if(sum[pos]==k){
        int ans=0,flag=pos;
        n-=pos;
        /*
        while(n){
            n-=1+pos;
            ans+=pos;
            pos++;
        }
        */
        int a=1+pos;
        int cnt=(sqrt(4*a*a+8*n)-2*a)/2;
        ans+=n-cnt;
        cout<<ans;
    }
    else{
        int ans=sum[pos]-k,flag=pos;
        n-=pos+ans;
        /*
        while(n){
            n-=1+pos;
            ans+=pos;
            pos++;
        }
        */
        int a=1+pos;
        int cnt=(sqrt(4*a*a+8*n)-2*a)/2;
        ans+=n-cnt;
        cout<<ans;
    }
    return 0;
}
