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
#define pub(a) push_back(a)
#define pob() pop_back()
#define pof() pop_front()
#define puf(a) push_front(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=100000;
typedef long long ll;

int n,m;
ll ans=0;
ll b[maxn+5],g[maxn+5];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    scii(n,m);
    re(i,1,n)
        scl(b[i]);
    re(i,1,m)
        scl(g[i]);
    sort(b+1,b+1+n,cmp);
    sort(g+1,g+1+m);
    re(i,1,n)
        ans+=b[i]*m;
    if(b[1]>g[1]){
        cout<<-1;
        return 0;
    }
    ll mxb=b[1];
    rre(i,m,1)
    {
        g[i]-=mxb;
        ans+=g[i];
    }
    if(g[1]!=0)
        ans+=(mxb-b[2]);
    pri(ans);
    return 0;
}
/*
2 3
0 0
1 2 3

2 3
0 0
0 0 0
*/
