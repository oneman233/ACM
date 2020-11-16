#include <bits/stdc++.h>
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define pri(a) printf("%d",a)
#define prn() printf("\n");
#define pb(a) push_back(a)
using namespace std;
const int maxn=200005;

int t,n,m,x,y;
vector<int> p[maxn];
int c[maxn];

void dfs(int i,int color)
{
    if(c[i]==t+1||c[i]==t+1+maxn)
        return;
    c[i]=color;
    for(int j=0;j<p[i].size();++j)
        dfs(p[i][j],2*t+2+maxn-color);
}

void init()
{
    for(int i=1;i<=n;++i)
        p[i].clear();
}

void out()
{
    int ct=0;
    for(int i=1;i<=n;++i)
        if(c[i]==t+1)
            ct++;
    if(ct<=n/2){
        pri(ct);
        prn();
        for(int i=1;i<=n;++i){
            if(c[i]==t+1)
                printf("%d ",i);
        }
        prn();
    }
    else{
        pri(n-ct);
        prn();
        for(int i=1;i<=n;++i){
            if(c[i]==t+1+maxn)
                printf("%d ",i);
        }
        prn();
    }
}

void debug()
{
    cout<<t<<endl;
    for(int i=1;i<=n;++i)
        cout<<c[i]<<" ";
    cout<<endl;
}

int main()
{
    sci(t);
    while(t--){
        scii(n,m);
        init();
        while(m--){
            scii(x,y);
            p[x].pb(y);
            p[y].pb(x);
        }
        dfs(1,t+1);
        out();
        //debug();
    }
    return 0;
}
