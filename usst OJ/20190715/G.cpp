#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
using namespace std;
typedef long long ll;
const int maxn=30005;

int t,p[maxn],bak[maxn],frt[maxn];
char ord[10];

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int fi(int x)
{
    if(x!=p[x])
    {
        int fa=p[x];
        p[x]=fi(p[x]);
        if(fa!=p[x])
            frt[x]+=frt[fa];
    }
    return p[x];
}

void me(int x,int y)
{
    int rx=fi(x);
    int ry=fi(y);
    if(rx!=ry)
    {
        p[rx]=ry;
        frt[rx]=bak[ry]+1;
        bak[ry]+=bak[rx]+1;
        fi(x);fi(y);
    }
}

signed main()
{
    for(int i=1;i<=30000;++i)
        p[i]=i,frt[i]=0,bak[i]=0;
    scl(t);
    while(t--)
    {
        int x,y;
        scanf("%s",ord);
        scl(x);scl(y);
        if(ord[0]=='M')
            me(x,y);
        else if(ord[0]=='C')
        {
            if(fi(x)!=fi(y))
                printf("-1\n");
            else
            {
                prl(max(frt[x],frt[y])-min(frt[x],frt[y])-1);
                printf("\n");
            }
        }
    }
    return 0;
}
