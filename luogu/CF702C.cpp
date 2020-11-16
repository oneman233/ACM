#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f3f3f3f3f;

int n,m;
int a[maxn],b[maxn];

bool chk(int r)
{
    for(int i=1;i<=n;++i){
        int pos=lower_bound(b+1,b+1+m,a[i])-b;
        if(a[i]-b[pos-1]>r&&b[pos]-a[i]>r)
            return false;
    }
    return true;
}

void half(int l,int r)
{
    while(l<=r){
        int m=(l+r)/2;
        if(chk(m))
            r=m-1;
        else
            l=m+1;
    }
    printf("%lld",l);
}

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    for(int j=1;j<=m;++j)
        scanf("%lld",&b[j]);
    b[0]=-inf;b[m+1]=inf;
    half(0,2000000000);
    return 0;
}
