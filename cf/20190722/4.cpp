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
bool chk(int m){}
int half(int l,int r){while(l<=r){int m=(l+r)/2;if(chk(m))r=m-1;else l=m+1;}return l;}

int n,m,k,ans=0;
int a[maxn];
int dp[maxn][15];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    re(i,1,n)
        cin>>a[i];
    memmn(dp);
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][0]=0;
            if(j==1)
                dp[i][j]=mmax(dp[i][j],dp[i-1][m]+a[i]-k,dp[i-1][0]+a[i]-k);
            else
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
/*
12 1 500000000
12 39045157 78090314 117135471 156180628 195225785 234270942 273316099 312361256 351406413 390451570 1000000000
*/
