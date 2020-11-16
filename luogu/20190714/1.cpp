#include <iostream>
#include <cstdio>
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

int n,len;
bool p[1025][1025];

void dfs(int x1,int y1,int x2,int y2)
{
    if(x2==x1+1&&y2==y1+1){
        p[x1][y1]=0;
        p[x1+1][y1]=1;
        p[x1][y1+1]=1;
        p[x1+1][y1+1]=1;
        return;
    }
    for(int i=x1;i<=(x1+x2)/2;++i){
        for(int j=y1;j<=(y1+y2)/2;++j){
            p[i][j]=0;
        }
    }
    dfs(x1,(y1+y2)/2+1,(x1+x2)/2,y2);
    dfs((x1+x2)/2+1,y1,x2,(y1+y2)/2);
    dfs((x1+x2)/2+1,(y1+y2)/2+1,x2,y2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    len=(1<<n);
    dfs(1,1,len,len);
    for(int i=1;i<=len;++i){
        printf("%d",p[i][1]);
        for(int j=2;j<=len;++j){
            printf(" %d",p[i][j]);
        }
        prn();
    }
    return 0;
}
