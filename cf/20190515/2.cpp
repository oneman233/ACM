#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=500000;
typedef long long ll;

int n,m;
int pre[maxn+5],r[maxn+5];

int f(int x)
{
    if(x==pre[x])
        return pre[x];
    else{
        int tmp=f(pre[x]);
        pre[x]=tmp;
        return tmp;
    }
}

void mer(int x,int y)
{
    int xr=f(x),yr=f(y);
    if(xr!=yr){
        if(r[xr]>=r[yr]){
            pre[yr]=xr;
            r[xr]+=r[yr];
        }
        else{
            pre[xr]=yr;
            r[yr]+=r[xr];
        }
    }
}

int main()
{
    scii(n,m);
    re(i,1,n)
    {
        pre[i]=i;
        r[i]=1;
    }
    re(i,1,m)
    {
        int tmp,root,son;
        sci(tmp);
        if(tmp!=0){
            sci(root);
            re(i,1,tmp-1)
            {
                sci(son);
                mer(son,root);
            }
        }
    }
    re(i,1,n)
    {
        printf("%d",r[f(i)]);
        if(i!=n)
            printf(" ");
    }
    return 0;
}
