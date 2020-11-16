#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
#define debug(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

ll n,m,k;
ll num[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	int cnt =0,tem =0;
	for(int i =0;i<m;++i){
		cin >> num[i];
	}
	ll l = 0,r = 0;
	int ans =0;
	for(int i =0;i<m;++i){
		if(num[i]-cnt>=l&&num[i]-cnt<=r){
			tem++;
		}
		else{
			cnt+=tem;
			tem = 0;
			ans ++;
			l = max(((num[i]-cnt-1)/k)*k,(ll)0)+1;
			r = l+k-1;
			tem ++;
		}
	}
	cout << ans;
	return 0;
}
