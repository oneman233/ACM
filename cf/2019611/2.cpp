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
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,m;
char p[505][505];

bool ok(int i,int j)
{
    if(i<1||i>n||j<1||j>m||p[i][j]=='.')
        return false;
    return true;
}

bool start(int i,int j)
{
    if(!ok(i+1,j)||!ok(i-1,j)||!ok(i,j+1)||!ok(i,j-1))
        return false;
    return true;
}

void dfs(int i,int j,int d)
{
    if(!ok(i,j))
        return;
    p[i][j]='.';
    if(d==0){
        dfs(i+1,j,1);
        dfs(i-1,j,2);
        dfs(i,j+1,3);
        dfs(i,j-1,4);
    }
    else if(d==1)
        dfs(i+1,j,1);
    else if(d==2)
        dfs(i-1,j,2);
    else if(d==3)
        dfs(i,j+1,3);
    else if(d==4)
        dfs(i,j-1,4);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(p[i][j]=='*'&&start(i,j)){
                dfs(i,j,0);
                break;
            }
        }
    }
    bool can=true;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(p[i][j]=='*'){
                can=false;
                break;
            }
        }
    }
    if(can)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
