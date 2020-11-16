#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 1;
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
 
 
signed main(void){
    int q;
    scanf("%lld",&q);
    while(q--){
        int c,m,x;
        scanf("%lld%lld%lld",&c,&m,&x);
        if(c>m)swap(c,m);
        x = x + m-c;
        if(x>=c)printf("%lld\n",c);
        else{
            if((c+c+x)%3==1)printf("%lld\n",(c+c+x)/3);
            else printf("%lld\n",x+(c-x)/3*2);
//            int cha = c-x,ans;
//            if(cha%3==2){
//                ans = x + cha / 3
//            }
        }
 
    }
}
