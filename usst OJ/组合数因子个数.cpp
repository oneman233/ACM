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
const int MAX=1000;
const int inf=0x3f3f3f3f;
const double pi=3.1415926535;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int m,n;
bool isp[MAX+5];
vector<int> p;
int cnt[MAX+5];

void init()
{
    memset(isp,0,sizeof(isp));
    memset(cnt,0,sizeof(cnt));
    p.clear();
}

void sieve()
{
    init();
    re(i,2,MAX)
    {
        if(!isp[i])
            p.pub(i);
        fo(j,0,p.size())
        {
            if(i*p[j]>MAX)
                break;
            isp[i*p[j]]=true;
            if(i%p[j]==0)
                break;
        }
    }
}

void c(int x)
{
    if(x==1)
        return;
    fo(i,0,p.size())
    {
        while(x%p[i]==0&&x!=0){
            cnt[i]++;
            x/=p[i];
        }
        if(x==0)
            break;
    }
}

void rc(int x)
{
    if(x==1)
        return;
    fo(i,0,p.size())
    {
        while(x%p[i]==0&&x!=0){
            cnt[i]--;
            x/=p[i];
        }
        if(x==0)
            break;
    }
}

int main()
{
    sieve();
    /*
    for(auto i:p)
        cout<<i<<" ";
    */
    scii(n,m);
    if(n==m)
        cout<<1;
    else{
        rre(i,n,n-m+1)
            c(i);
        re(i,1,m)
            rc(i);
        ll ans=1;
        fo(i,0,p.size())
            ans*=(cnt[i]+1);
        prl(ans);
    }
    return 0;
}
/*
5 1
5 3
*/
