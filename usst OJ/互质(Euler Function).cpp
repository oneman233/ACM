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

bool isp[MAX+5];
vector<int> p;
int e[MAX+5];

int cal(int n)
{
    int res=n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            res-=res/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}

void init()
{
    memset(e,0,sizeof(e));
    p.clear();
    memset(isp,0,sizeof(isp));
}

void sieve()
{
    init();
    e[1]=1;
    re(i,2,MAX)
    {
        if(!isp[i]){
            p.pub(i);
            e[i]=i-1;
        }
        fo(j,0,p.size())
        {
            if(i*p[j]>MAX)
                break;
            isp[i*p[j]]=true;
            if(i%p[j]==0){
                e[i*p[j]]=e[i]*p[j];
                break;
            }
            else
                e[i*p[j]]=e[i]*(p[j]-1);
        }
    }
}

int main()
{
    sieve();
    int n;
    cin>>n;
    ///cout<<cal(n);
    cout<<e[n];
    return 0;
}
