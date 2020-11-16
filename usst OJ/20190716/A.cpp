#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,t,ans=0;
int a[maxn];

int main()
{
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j!=i&&abs(a[i]-a[j])<=t)
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
