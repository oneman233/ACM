#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
///typedef long long ll;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
const int maxn = 1e6;
const int maxm = 1e7;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

int a[maxn],b[maxn];
multiset<int> st;

#undef int
int main()
{
	#define int ll
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>b[i];
		st.insert(b[i]);
	}
	for(int i=0;i<n;i++){
		auto h = st.lower_bound(n-a[i]);
		if(h==st.end()){
			cout<<(a[i]+*st.begin())%n<<" ";
			st.erase(st.begin());
		}
		else{
			if(((*h+a[i])%n)<(*st.begin()+a[i])%n){
				cout<<(*h+a[i])%n<<" ";
				st.erase(h);
			}
			else{
				cout<<(*st.begin()+a[i])%n<<" ";
				st.erase(st.begin());
			}
		}
	}
	return 0;
}
