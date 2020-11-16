#include <bits/stdc++.h>
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define pri(a) printf("%d ",a)
using namespace std;
const int maxn=100005;

int n,m,x,y,tp;
int l[maxn],r[maxn];
int lend=1;

void del(int tp)
{
    l[r[tp]]=l[tp];
    r[l[tp]]=r[tp];
    r[tp]=l[tp]=0;
}

int main()
{
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    sci(n);
    for(int i=2;i<=n;++i){
        scii(x,y);
        if(y==0){
            if(lend==x)
                lend=i;
            l[i]=l[x];
            r[i]=x;
            r[l[x]]=i;
            l[x]=i;
        }
        else if(y==1){
            l[i]=x;
            r[i]=r[x];
            l[r[x]]=i;
            r[x]=i;
        }
    }
    sci(m);
    for(int i=1;i<=m;++i){
        sci(tp);
        if(l[tp]==0&&r[tp]==0)
            continue;
        if(lend==tp)
            lend=r[tp];
        del(tp);
    }
    int fg=lend;
    while(fg!=0){
        pri(fg);
        fg=r[fg];
    }
    return 0;
}
