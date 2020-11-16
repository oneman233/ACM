#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=200005;
typedef long long ll;

int n,m,x,y;
int xl[maxm],yl[maxm],xr[maxm],yr[maxm],k[maxm];
int cnt[1000005],tmp=0;
int ans=0;

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<m;++i)
        scanf("%lld %lld %lld %lld %lld",&xl[i],&yl[i],&xr[i],&yr[i],&k[i]);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;++i)
        cnt[xl[i]]+=k[i],cnt[xr[i]]+=k[i];
    tmp=0;
    for(int i=1;i<=1000000;++i){
        if(tmp<n&&tmp+cnt[i]>=n){
            x=i;
            break;
        }
        tmp+=cnt[i];
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;++i)
        cnt[yl[i]]+=k[i],cnt[yr[i]]+=k[i];
    tmp=0;
    for(int i=1;i<=1000000;++i){
        if(tmp<n&&tmp+cnt[i]>=n){
            y=i;
            break;
        }
        tmp+=cnt[i];
    }
    //cout<<x<<' '<<y<<endl;
    for(int i=0;i<m;++i){
        ans+=(abs(x-xl[i])+abs(x-xr[i])-xr[i]+xl[i])/2*k[i];
        ans+=(abs(y-yl[i])+abs(y-yr[i])-yr[i]+yl[i])/2*k[i];
    }
    printf("%lld",ans);
    return 0;
}
