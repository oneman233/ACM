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
#define mkp(a,b) make_pair(a,b)
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
const int big=1000000000;

int n,m;
int t,l,r;
int ans[1005];
bool can=true;
vector<pair<int,int> >no;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(ans,0,sizeof(ans));
    while(m--){
        cin>>t>>l>>r;
        if(t==1){
            for(int i=l;i<=r;++i)
                ans[i]=1;
        }
        else if(t==0){
            no.pub(mkp(l,r));
        }
    }
    for(int i=0;i<no.size();++i){
        bool flg=true;
        for(int j=no[i].first;j<=no[i].second;++j){
            if(j!=1&&ans[j]!=1){
                ans[j]=-1;
                flg=false;
                break;
            }
        }
        if(flg){
            can=false;
            break;
        }
    }
    if(can){
        cout<<"YES"<<endl;
        ans[1]=10000;
        cout<<ans[1];
        for(int i=2;i<=n;++i){
            cout<<' '<<ans[i]+ans[i-1];
            ans[i]+=ans[i-1];
        }
    }
    else{
        cout<<"NO";
    }
    return 0;
}
