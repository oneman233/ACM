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

const int MAXN =1e3+10;
int cnt[6];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tot = n;
	int tem;
	for(int i = 0;i<n;++i){
		cin >> tem;
		switch(tem){
			case 4:{
				cnt[0]++;
				break;
			}
			case 8:{
				cnt[1]++;
				if(cnt[1]>cnt[0])cnt[1]--,tot--;
				break;
			}
			case 15:{
				cnt[2]++;
				if(cnt[2]>cnt[1])cnt[2]--,tot--;
				break;
			}
			case 16:{
				cnt[3]++;
				if(cnt[3]>cnt[2])cnt[3]--,tot--;
				break;
			}
			case 23:{
				cnt[4]++;
				if(cnt[4]>cnt[3])cnt[4]--,tot--;
				break;
			}
			case 42:{
				cnt[5]++;
				if(cnt[5]>cnt[4])cnt[5]--,tot--;
				break;
			}
		}
	}
	int ans;
	ans = n-6*min(cnt[0],min(cnt[1],min(cnt[2],min(cnt[3],min(cnt[4],cnt[5])))));
	cout << ans;
	return 0;
}
