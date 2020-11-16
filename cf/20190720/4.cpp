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
const ll maxn=1000005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n;
bool isp[maxn];
vector<int> p;
int deg[maxn];

void get()
{
    isp[1]=1;
    for(int i=2;i<=maxn-5;++i){
        if(!isp[i])
            p.pub(i);
        for(int j=0;j<p.size();++j){
            if(i*p[j]>maxn-5)
                break;
            isp[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
}

vector<int> xx,yy;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    get();
    for(int i=1;i<=n-1;++i)
        xx.pub(i),yy.pub(i+1);
    xx.pub(n),yy.pub(1);
    if(!isp[xx.size()]){
        cout<<xx.size()<<endl;
        for(int i=0;i<xx.size();++i)
            cout<<xx[i]<<' '<<yy[i]<<endl;
    }
    else{
        for(int i=1;i<=n;++i)
            deg[i]=2;
        int flag=1;
        while(isp[xx.size()]){
            if(deg[flag]==2){
                xx.pub(flag);
                yy.pub(flag+2);
                deg[flag]++;
                deg[flag+2]++;
            }
            else
                flag++;
        }
        cout<<xx.size()<<endl;
        for(int i=0;i<xx.size();++i)
            cout<<xx[i]<<' '<<yy[i]<<endl;
    }
    return 0;
}
