#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define re(i,a,b) for(int i=a;i<=b;++i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define prn() printf("\n")
#define prs() printf(" ")
#define mkp make_pair
#define pii pair<int,int>
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst first
#define snd second
#define frt front()
#define bak back()
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
#define debug
#define db double
#define yyes cout<<"YES"<<endl;
#define nno cout<<"NO"<<endl;
using namespace std;
typedef vector<int> vec;
const int maxn=500005;
const int inf=0x3f3f3f3f3f3f3f3f;
const int MOD=1e+7;
const db eps=1e-8;
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
bool smlequal(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}

bool can=false;
db d1,c,d2,pp,ans=inf;
int n;
struct station
{
    db d,p;
    bool operator <(station s){return smlequal(d,s.d);}
}s[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>d1>>c>>d2>>pp>>n;
    fo(i,0,n)
        cin>>s[i].d>>s[i].p;
    if(n!=0)
        sort(s,s+n);
    fo(i,0,(1<<n))
    {
        db cnt=0.0,now=0.0;
        bool flg=true;
        vec idx;
        fo(j,0,n)
            if(i&(1<<j))
                idx.pub(j);
        int lst=idx.size()-1;
        if(idx.size()!=0){
            if(!smlequal(s[idx[0]].d/d2,c))
                flg=false;
            else{
                bool full=true;
                fo(i,0,idx.size())
                {
                    if(s[idx[i]].p<pp){
                        full=false;
                        break;
                    }
                }
                if(full)
                    cnt+=c*pp,
                    now=c-s[idx[0]].d/d2;
                else
                    cnt+=s[idx[0]].d/d2*pp;
            }
        }///head
        fo(i,1,idx.size())
        {
            if(!smlequal((s[idx[i]].d-s[idx[i-1]].d)/d2,c))
                flg=false;
            else{
                bool full=true;
                fo(j,i,idx.size())
                {
                    if(s[idx[j]].p<s[idx[i-1]].p){
                        full=false;
                        break;
                    }
                }
                if(full){
                    cnt+=(c-now)*s[idx[i-1]].p;
                    now=c-(s[idx[i]].d-s[idx[i-1]].d)/d2;
                }
                else{
                    if((s[idx[i]].d-s[idx[i-1]].d)/d2>now)
                        cnt+=((s[idx[i]].d-s[idx[i-1]].d)/d2-now)*s[idx[i-1]].p,
                        now=0.0;
                    else
                        now-=(s[idx[i]].d-s[idx[i-1]].d)/d2;
                }
            }
        }///mid
        if(idx.size()!=0){
            if(!smlequal((d1-s[idx[lst]].d)/d2,c))
                flg=false;
            else
                if((d1-s[idx[lst]].d)/d2>now)
                    cnt+=((d1-s[idx[lst]].d)/d2-now)*s[idx[lst]].p;
        }
        else{
            if(!smlequal(d1/d2,c))
                flg=false;
            else
                cnt+=d1/d2*pp;
        }///tail
        #undef debug
        #ifdef debug
        cout<<"flg= "<<flg<<" i= "<<i<<" cnt= "<<cnt<<endl;
        #endif
        if(flg){
            ans=min(ans,cnt);
            can=true;
        }
    }
    if(can)
        printf("%.2lf",ans);
    else
        cout<<"No Solution";
    return 0;
}
/*
475.6 11.9 27.4 14.98 6
102.0 9.99
220.0 13.29
256.3 14.79
275.0 10.29
277.6 11.29
381.8 10.09

*/
