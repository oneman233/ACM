#include <bits/stdc++.h>
#define int long long
#define sc(a) scanf("%lld",&a)
#define pr(a) printf("%lld",a)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define re(i,a,b) for(int i=a;i<=b;++i)
#define prn() printf("\n")
#define prs() printf(" ")
#define mkp make_pair
#define pub(a) push_back(a)
#define pob() pop_back
#define puf(a) push_front(a)
#define pof() pop_front()
#define fst frist
#define snd second
#define mem0(a) memset(a,0,sizeof(a))
#define memmx(a) memset(a,0x3f3f,sizeof(a))
#define memmn(a) memset(a,-0x3f3f,sizeof(a))
using namespace std;
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

int n,a[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    re(i,1,n)
        cin>>a[i];
    int mx=-inf,pos;
    re(i,1,n)
    {
        if(a[i]>mx){
            mx=a[i];
            pos=i;
        }
    }
    bool can=true;
    for(int i=pos+1;i<=n;++i){
        if(a[i]>a[i-1]){
            can=false;
            break;
        }
    }
    for(int i=pos-1;i>=0;--i){
        if(a[i]>a[i+1]){
            can=false;
            break;
        }
    }
    if(can)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
