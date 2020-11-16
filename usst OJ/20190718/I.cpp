#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;

int n,d,k;
int x[maxn],s[maxn];
int dp[maxn];

bool check(int g)
{
    memset(dp,-0x3f3f,sizeof(dp));
    dp[0]=0;
    int l=max(1LL,d-g);
    int r=d+g;
    int mx=0;
    for(int i=1;i<=n;++i){
        for(int j=mx;j<i;++j){
            if(l<=x[i]-x[j]&&x[i]-x[j]<=r){
                if(dp[i]<dp[j]+s[i]){
                    dp[i]=dp[j]+s[i];
                    mx=j;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        if(dp[i]>=k)
            return true;
    return false;
}

signed main()
{
    scanf("%lld %lld %lld",&n,&d,&k);
    int sum=0;
    for(int i=1;i<=n;++i)
        scanf("%lld %lld",&x[i],&s[i]),sum+=max(0LL,s[i]);
    if(sum<k){
        printf("-1");
        return 0;
    }
    int l=0,r=1e9;
    while(l<=r){
        int m=(l+r)/2;
        if(check(m))
            r=m-1;
        else
            l=m+1;
    }
    printf("%lld",l);
    return 0;
}
