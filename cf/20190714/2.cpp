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
using namespace std;
typedef long long ll;
const ll maxn=50005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int t,ans=inf;
int n,m,row[maxn],col[maxn];
char c[maxn];
vector<char> p[maxn];

int main()
{
    scanf("%d",&t);
    while(t--){
        ans=inf;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
            p[i].clear();
        for(int i=0;i<n;++i){
            scanf("%s",c);
            for(int j=0;j<m;++j){
                p[i].pub(c[j]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(p[i][j]=='.')
                    row[i]++;
            }
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(p[i][j]=='.')
                    col[j]++;
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(col[j]+row[i]<=ans){
                    if(p[i][j]=='.'){
                        ans=min(ans,col[j]+row[i]-1);
                    }
                    else{
                        ans=min(ans,col[j]+row[i]);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
