#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll pw[115],f[115];
int cnt;
void init(){
    pw[0]=1;
    f[0]=pw[0]-1;
    for(int i=1;i<=105;i++){
        pw[i]=pw[i-1]*2;
        f[i]=pw[i]-1;
        if(pw[i]>(ll)1e18){
            cnt=i;
            break;
        }
    }
}
ll solve(int k,ll n){
    if(k==1){
        return 2ll;
    }
    ll mid=pw[k-1]/2;
    if(n<=mid){
        return solve(k-1,n);
    }else{
        return 2ll*solve(k-1,n-mid);
    }
}
int main(){
    init();
    scanf("%lld",&n);
    int k=lower_bound(f+1,f+1+cnt,n)-f;
    ll ans=solve(k,n-f[k-1]);
    printf("%lld\n",ans);
    return 0;
}
