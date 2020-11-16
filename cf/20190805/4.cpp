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
//#define debug
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

int n,m,k,q;
struct pic
{
    int x,y;
}p[maxn];
vector<int> row[maxn],b;
int bb;
int safe[maxn],to[maxn];

bool cmp(pic a,pic b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    else
        return a.y<b.y;
}

signed main()
{
    int mxn=-inf;
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k>>q;
    re(i,1,k)
        cin>>p[i].x>>p[i].y,
        mxn=max(mxn,p[i].x);
    sort(p+1,p+1+k,cmp);
    re(i,1,k)
        row[p[i].x].pub(p[i].y);
    re(i,1,q)
        cin>>bb,
        b.pub(bb);
    memmx(safe);
    re(i,1,m)
    {
        int pos=lower_bound(b.begin(),b.end(),i)-b.begin();
        if(pos>0&&pos<b.size()){
            safe[i]=min(b[pos]-i,i-b[pos-1]);
            if(b[pos]-i<i-b[pos-1])
                to[i]=b[pos];
            else
                to[i]=b[pos-1];
        }
        else if(pos==0){
            safe[i]=b[pos]-i;
            to[i]=b[pos];
        }
        else if(pos==b.size()){
            safe[i]=i-b[pos-1];
            to[i]=b[pos-1];
        }
    }
    int now=1,ans=0;
    re(hang,1,mxn)
    {
        #ifdef debug
        cout<<"now "<<now<<endl;
        cout<<"ans "<<ans<<endl;
        #endif
        if(row[hang].size()>=1){
            int head=row[hang][0],tail=row[hang][row[hang].size()-1];
            int len=tail-head;
            if(now<=head){
                ans+=tail-now;
                now=tail;
            }
            else if(now>=tail){
                ans+=now-head;
                now=head;
            }
            else{
                if(tail-now+safe[tail]<=now-head+safe[head]){
                    ans+=len+tail-now;
                    now=tail;
                }
                else{
                    ans+=len+now-head;
                    now=head;
                }
            }
        }
        /*
        else if(row[hang].size()==1){
            ans+=abs(row[hang][0]-now);
            now=row[hang][0];
            ans+=safe[now];
            now=to[now];
        }
        */
        if(hang!=mxn){
        ans+=safe[now];
        now=to[now];
        ans++;
        }
    }
    cout<<ans;
    return 0;
}
/*
2 2 2 2
1 1
1 2
1 2
*/
