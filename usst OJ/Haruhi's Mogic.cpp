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
using namespace std;
const int MAX=1000000;
const int inf=0x3f3f3f3f;
const double pi=3.1415926535;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int t;
bool isp[MAX+5];
ll a,b,k,u[MAX+5];
vector<ll> p;

void sieve()
{
    memset(isp,0,sizeof(isp));
    p.clear();
    memset(u,0,sizeof(u));
    u[1]=1;
    re(i,2,MAX)
    {
        if(!isp[i]){
            p.pub(i);
            u[i]=-1;
        }
        fo(j,0,p.size())
        {
            if(i*p[j]>MAX)
                break;
            isp[i*p[j]]=true;
            if(i%p[j]==0){
                u[i*p[j]]=0;
                break;
            }
            else
                u[i*p[j]]=-u[i];
        }
    }
}

/*g(i)=(a/i)*(b/i)*/

int main()
{
    sieve();
    sci(t);
    while(t--){
        scll(a,b);
        scl(k);
        ll sum=0;
        for(ll i=k;i<=min(a,b);i+=k)
            sum+=u[i/k]*(a/i)*(b/i);
        prl(sum);
        prn();
    }
    return 0;
}
/*
2
3 5 1
6 3 3
*/
