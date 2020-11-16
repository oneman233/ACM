#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=2005;

int n,m;
int x[M],y[M];
set<int> s;

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",&x[i]);
    for(int j=1;j<=m;++j)
        scanf("%lld",&y[j]);
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i){
            if(x[i]>=y[j])
                s.insert(x[i]-y[j]);
        }
    }
    for(int i=0;i<=1000000000LL;++i){
        if(s.count(i)==0){
            printf("%lld",i);
            break;
        }
    }
    return 0;
}
