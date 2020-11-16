#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define scc(a,b) scanf("%lld %lld",&a,&b)
#define sccc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define schar(a) scanf("%c",&a)
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
const db eps=1e-10;
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
int mm(int l,int r){return (l+r)/2;}
int lg(int x){return (int)log2(x)+1;}
bool smleql(db a,db b){if(a<b||fabs(a-b)<=eps)return true;return false;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}

int q,x,y,sum=0,now=0;
char c;
int same[maxn],tag[maxn],del[maxn];

void build(int p,int l,int r)
{
    same[p]=1;
    tag[p]=0;
    if(l==r)
        return;
    int m=mm(l,r);
    build(ll(p),l,m);
    build(rr(p),m+1,r);
}

void down(int p)
{
    same[p]=0;
    if(tag[p]==0)
        return;
    tag[ll(p)]=tag[rr(p)]=tag[p];
    tag[p]=0;
}

void seek(int p,int l,int r,int val)
{
    if(same[p]){
        if(!del[tag[p]]&&tag[p]!=0)
            sum--,now++;
        del[tag[p]]=1;
        tag[p]=val;
        return;
    }
    int m=mm(l,r);
    seek(ll(p),l,m,val);
    seek(rr(p),m+1,r,val);
    tag[p]=val;
    same[p]=1;
}

void add(int p,int l,int r,int L,int R,int val)
{
    if(L<=l&&r<=R){
        seek(p,l,r,val);
        return;
    }
    int m=mm(l,r);
    down(p);
    if(L<=m) add(ll(p),l,m,L,R,val);
    if(R>m) add(rr(p),m+1,r,L,R,val);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    build(1,1,100000);
    sc(q);
    re(i,1,q){
        getchar();
        getchar();
        schar(c);
        if(c=='A'){
            scc(x,y);
            now=0;
            sum++;
            add(1,1,100000,x,y,i);
            pr(now);
            prn();
        }
        else if(c=='B'){
            pr(sum);
            prn();
        }
    }
    return 0;
}
