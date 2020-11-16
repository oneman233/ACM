#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000005;

int n,d;
struct point
{
    int x[5];
}p[maxn];
int mx[16],mn[16];

signed main()
{
    scanf("%lld %lld",&n,&d);
    for(int i=0;i<n;++i){
        for(int j=0;j<d;++j){
            scanf("%lld",&p[i].x[j]);
        }
    }
    memset(mx,-0x3f,sizeof(mx));
    memset(mn,0x3f,sizeof(mn));
    for(int ix=0;ix<n;++ix){
        for(int i=0;i<(1<<d);++i){
            int cnt=0;
            for(int j=0;j<d;++j){
                if(i&(1<<j))
                    cnt+=p[ix].x[j];
                else
                    cnt-=p[ix].x[j];
            }
            mx[i]=max(mx[i],cnt);
            mn[i]=min(mn[i],cnt);
        }
    }
    int ans=-0x3f3f3f3f,tot=1<<d;
    for(int i=0;i<tot;++i){
        ans=max(ans,mx[i]-mn[i]);
        ans=max(ans,mn[i]-mx[i]);
    }
    printf("%lld",ans);
    return 0;
}
