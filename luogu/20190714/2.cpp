#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
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

int n,init[maxn],order[maxn];
unordered_map<int,int> pos;
bool del[maxn];
int nxt[maxn],pre[maxn];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    sci(n);
    re(i,1,n)
    {
        sci(init[i]);
        order[i]=init[i];
        pos[init[i]]=i;
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    nxt[n]=-1;
    pre[1]=-1;
    sort(order+1,order+n+1,cmp);
    re(i,1,n)
    {
        int p=pos[order[i]];
        if(!del[p]){
            /*
            if(nxt[p]==-1){
                printf("%d ",init[pre[p]]);
                printf("%d ",init[p]);
                del[p]=true;
                del[pre[p]]=true;
                nxt[pre[pre[p]]]=nxt[p];
                pre[nxt[p]]=pre[pre[p]];
            }*/
            if(nxt[p]!=-1){
                printf("%d ",init[p]);
                printf("%d ",init[nxt[p]]);
                del[p]=true;
                del[nxt[p]]=true;
                nxt[pre[p]]=nxt[nxt[p]];
                pre[nxt[nxt[p]]]=pre[p];
            }
        }
    }
    return 0;
}
