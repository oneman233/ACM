#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q[2000005],z,hd=0,
ed=0,a[2000005],ans=0;

int main()
{
    scanf("%lld%lld",&n,&z);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(hd!=ed&&a[q[hd]]+z<=a[i])
        {
            //printf("%d %d\n",a[q[hd]],a[i]);
            ans++,hd++;
            continue;
        }
        q[ed++]=i;
    }
    printf("%lld",ans);
    return 0;
}
