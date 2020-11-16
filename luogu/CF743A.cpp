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

int n,a,b;
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>a>>b>>s;
    a--,b--;
    if(s[a]==s[b])
        cout<<0;
    else{
        int mx=max(a,b)-min(a,b);
        int cnt=0;
        bool can=false;
        for(int i=a;i<n;++i,++cnt){
            if(s[i]==s[b]){
                can=true;
                break;
            }
            else cnt=0;
        }
        if(can)
            mx=min(mx,cnt);
        cnt=0,can=false;
        for(int i=a;i>=0;--i,++cnt){
            if(s[i]==s[b]){
                can=true;
                break;
            }
            else
                cnt=0;
        }
        if(can)
            mx=min(mx,cnt);
        cnt=0,can=false;
        for(int i=b;i<n;++i,++cnt){
            if(s[i]==s[a]){
                can=true;
                break;
            }
            else
                cnt=0;
        }
        if(can)
            mx=min(mx,cnt);
        cnt=0,can=false;
        for(int i=b;i>=0;--i,++cnt){
            if(s[i]==s[a]){
                can=true;
                break;
            }
            else
                cnt=0;
        }
        if(can)
            mx=min(mx,cnt);
        cout<<mx;
    }
    return 0;
}
