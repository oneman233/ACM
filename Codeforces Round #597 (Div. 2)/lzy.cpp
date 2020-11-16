#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 2010;
const int mxm = 6e6+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int cost[mxn][mxn],x[mxn],y[mxn],c[mxn],k[mxn];

//kruskal
int fa[mxn];
struct edge{
    int from,to,val;
}e[mxm];
int cnt=0;
void addedge(int x,int y,int w){
    e[++cnt].from=x;
    e[cnt].to=y;
    e[cnt].val=w;
    return;
}
int _find(int x){if(x!=fa[x]) return fa[x]=_find(fa[x]); return fa[x];   }
void _union(int x,int y){fa[_find(x)]=fa[_find(y)]; }

int m;
vector<pr> ans;
int res = 0;
bool cmp(edge x,edge y){
    if(x.val!=y.val) return x.val<y.val;
    else if(x.from!=y.from)return x.from<y.from;
    else return x.to<y.to;
}
void kruskal(int nn){
    ans.clear();
    sort(e+1,e+m+1,cmp);
    int sz=0;
    for(int i=1;i<=m;i++){
        if(_find(e[i].from)==_find(e[i].to)) continue;
        ans.push_back(mpr(e[i].from,e[i].to));
//        printf("u = %lld, v=%lld,w=%lld\n",e[i].from,e[i].to,e[i].val);
        res += e[i].val;
        _union(e[i].from,e[i].to);
        sz++;
        if(sz==nn-1) break;
    }
    return;
}

signed main(void){
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n+5;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int dis = llabs(x[i]-x[j]) + llabs(y[i] - y[j]);
            cost[i][j] = dis * (k[i]+k[j]);
//            printf("i=%lld,j=%lld,cost=%lld\n",i,j,cost[i][j]);
        }
    }
    m = n*(n-1)/2 + n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            addedge(i,j,cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        addedge(n+1,i,c[i]);
    }
    kruskal(n+1);
    printf("%lld\n",res);
    vector<int> pp;
    vector<pr>qq;
    for(int i=0;i<ans.size();i++){
        if(ans[i].fi==n+1){
            pp.pb(ans[i].se);
        }
        else if(ans[i].se==n+1){
            pp.pb(ans[i].fi);
        }
        else{
            qq.pb(ans[i]);
        }
    }
    printf("%lld\n",pp.size());
    for(int i=0;i<pp.size();i++){
        printf("%lld ",pp[i]);
    }
    printf("\n");
    printf("%lld\n",qq.size());
    for(int i=0;i<qq.size();i++){
        printf("%lld %lld\n",qq[i].fi,qq[i].se);
    }
}
