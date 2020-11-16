#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,a[100010];
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    long long ans=1;
    long long tmpsum=0;
    for(int i=0;i<n;++i)
    {
        if(tmpsum+a[i]<=m)
            tmpsum+=a[i];
        else
        {
            tmpsum=a[i];
            ++ans;
        }
    }
    printf("%lld",ans);
    return 0;
}
