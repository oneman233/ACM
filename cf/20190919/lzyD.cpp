#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 5e5+5;
const int mxm = 1;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int inf = 1e18+5;
int a[mxn],b[mxn];
int dp[mxn][6];
signed main(void){
    int q;
    scanf("%lld",&q);
    while(q--){
        int n;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
//            dp[i][0]=dp[i][1]=dp[i][3]=inf;
            for(int k=0;k<6;k++){
                dp[i][k] = inf;
            }
        }
        for(int k=0;k<6;k++){
            dp[1][k] = k*b[1];
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    if(a[i]+j==a[i-1]+k)continue;
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+j*b[i]);
                }
            }
        }
        int res = inf;
        for(int i=0;i<6;i++){
            res = min(res,dp[n][i]);
        }
        printf("%lld\n",res);
    }
}
