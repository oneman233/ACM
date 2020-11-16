#include <bits/stdc++.h>
#define mi(a,b) a>b?b:a
using namespace std;
const int mod=100003;

int n,k;
int ans[100005];

int main()
{
    scanf("%d%d",&n,&k);
    ans[1]=1;
    for(int i=2;i<=n;++i)
        for(int j=mi(i-1,k);j>=1;--j)
            ans[i]+=ans[i-j],ans[i]%=mod;
    printf("%d",ans[n]);
    return 0;
}
