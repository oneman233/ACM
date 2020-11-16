#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,mx=-0x3f3f3f3f;
int p[2505][2505];
int dp[2505][2505];

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%lld",&p[i][j]);
        }
    }

    printf("%lld",mx);
    return 0;
}
