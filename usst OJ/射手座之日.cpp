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
const int maxn=300000;
typedef long long ll;

int n,m;
int pre[50005],r[50005];
bool isdel[50005];
int op,x,y;

int fin(int x)
{
    if(x==pre[x])
        return x;
    else{
        pre[x]=fin(pre[x]);
        return pre[x];
    }
}

int mer(int x,int y)
{
    int tx=fin(x);
    int ty=fin(y);
    if(tx!=ty){
        if(r[tx]>=r[ty]){
            pre[ty]=tx;
            r[tx]+=r[ty];
        }
        else{
            pre[tx]=ty;
            r[ty]+=r[tx];
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
        isdel[i]=false;
    }
    while(m--){
        scii(op,x);
        if(op==1){
            sci(y);
            mer(x,y);
        }
        else if(op==2){
            if(!isdel[x]){
                isdel[x]=true;
                r[fin(x)]--;
            }
        }
        else if(op==3){
            pri(r[fin(x)]);
            prn();
        }
    }
    return 0;
}
