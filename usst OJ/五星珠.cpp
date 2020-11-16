#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[5005],ans;

void f(int l,int r)
{
    if(l>r)
        return;
    bool all=true;
    for(int i=l;i<=r;++i){
        if(a[i]!=0){
            all=false;
            break;
        }
    }
    if(all)
        break;
    ll sml=1e9+5;
    int cnt=0;
    for(int i=l;i<=r;++i)
        sml=min(sml,a[i]);
    for(int i=l;i<=r;++i)
        if(a[i]!=0)
            cnt++;
    ans=min(ans,cnt+sml);
}

int main()
{
    scanf("%d",&n);
    ans=n;
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    f(0,n-1);
    printf("%lld",ans);
    return 0;
}
/*
5
5 3 3 4 4
*/
