#include <bits/stdc++.h>
#define int long long
#define scl(a) scanf("%lld",&a)
#define prl(a) printf("%lld",a)
#define frt() front()
#define bak() back()
#define pb(a) push_back(a)
#define po() pop_front()
using namespace std;
typedef long long ll;
const int maxn=1000005;

int n,k,sum=0,ans=-0x3f3f3f3f;
int a[maxn];
deque<int> dq;

signed main()
{
    scl(n);
    scl(k);
    for(int i=0;i<n;++i)
        scl(a[i]);
    for(int i=0;i<k;++i)
    {
        dq.pb(a[i]);
        sum+=a[i];
    }
    ans=max(ans,sum);
    for(int i=k;i<n;++i)
    {
        dq.pb(a[i]);
        sum+=a[i];
        sum-=dq.frt();
        dq.po();
        ans=max(ans,sum);
    }
    prl(ans);
    return 0;
}
