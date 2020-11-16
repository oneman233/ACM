#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
using namespace std;
typedef long long ll;

int t,a,b;

signed main()
{
    scl(t);
    while(t--)
    {
        scl(a);
        scl(b);
        if(a>b)
        {
            int tmp=a;
            a=b;
            b=tmp;
        }
        int ans=0;
        while((ll)log2(a)!=(ll)log2(b))
            b>>=1,ans++;
        while(a!=b)
        {
            a>>=1;
            b>>=1;
            ans+=2;
        }
        prl(ans);
        printf("\n");
    }
    return 0;
}
