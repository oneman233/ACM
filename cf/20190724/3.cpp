#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define re(i,a,b) for(int i=a;i<=b;++i)
#define prn() printf("\n")
#define prs() printf(" ")
#define mkp make_pair
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst frist
#define snd second
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define debug
using namespace std;
typedef vector<int> vec;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=1e+7;
int qpow(int a,int b){int tmp=a,ans=1;while(b){if(b&1){ans*=tmp,ans%=MOD;}tmp*=tmp,tmp%=MOD,b>>=1;}return ans;}
int lowbit(int x){return x&-x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int mmax(int a,int b,int c){return max(a,max(b,c));}
int mmin(int a,int b,int c){return min(a,min(b,c));}
void mod(int &a){a+=MOD;a%=MOD;}
bool chk(int cost){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}
int ll(int p){return p<<1;}
int rr(int p){return p<<1|1;}
int lg(int x){return (int)log2(x)+1;}

int q,n;
int x,y,f1,f2,f3,f4;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>q;
    while(q--){
        bool can=true;
        int nowxl=-100000,nowxr=100000,nowyu=100000,nowyd=-100000;
        int xl,xr,yu,yd;
        cin>>n;
        re(i,1,n)
        {
            cin>>x>>y>>f1>>f2>>f3>>f4;
            //cout<<nowxl<<' '<<nowxr<<' '<<nowyu<<' '<<nowyd<<endl;
            xl=x,xr=x,yu=y,yd=y;
            if(f1==1){
                xl=-100000;
            }
            if(f3==1){
                xr=100000;
            }
            if(f2==1){
                yu=100000;
            }
            if(f4==1){
                yd=-100000;
            }
            if(xl>nowxr||xr<nowxl||yu<nowyd||yd>nowyu){
                can=false;
            }
            nowxl=max(nowxl,xl);
            nowxr=min(nowxr,xr);
            nowyu=min(nowyu,yu);
            nowyd=max(nowyd,yd);
        }
        if(can)
            cout<<1<<' '<<nowxl<<' '<<nowyd<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
