#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
using namespace std;
const int maxn=200005;

int n,k,s,t;
int c[maxn],v[maxn],g[maxn];

bool chk(int m)
{

}

int half(int l,int r)
{
    while(l<=r){
        int m=(l+r)/2
        if(chk(m))
            r=m-1;
        else
            l=m+1;
    }
    return l;
}

signed main()
{
    scl(n),scl(k),scl(k),scl(t);
    for(int i=1;i<=n;++i)
        scl(c[i]),scl(v[i]);
    for(int i=1;i<=k;++i)
        scl(g[i]);

    return 0;
}
