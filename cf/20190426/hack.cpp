#include <bits/stdc++.h>
#define fff cout<<"***"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define lowbit(x) (x&-x)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
#define pii pair<int,int>
using namespace std;
#if __cplusplus >= 201100
void de() {
	cout << endl;
}
template <typename F, typename... T>
void de(F & f, T&...  t) {
	cout << f << " ";
	de(t...);
}
#endif
typedef long long ll;
const double INF=0x3f3f3f3f;
const double EPS=1e-6;
const double EPS2=1e-10;
const double PI=acos(-1.);
const int MAXN=200000+10;
const int MOD=1e9+7;
void ptm() {freopen("datain.txt","r",stdin);}
int arr[MAXN];
vector<char> ans;
int main() {
	//ptm();
	int n;
	cin>>n;
	for (int i=1;i<=n;++i) {
		cin>>arr[i];
	}
	int l=1,r=n;
	int minn=0;
	while (l!=r) {
		if (arr[l]<=minn && arr[r]<=minn) break;
		if (arr[l]<=minn && arr[r]>minn) {
			for (int i=r;i>l;--i) {
				if (arr[i]>minn) {
					ans.pb('R');
					minn=arr[i];
				}
				else {
					break;
				}
			}
			break;
		}
		if (arr[l]>minn && arr[r]<=minn) {
			for (int i=l;i<r;++i) {
				if (arr[i]>minn) {
					ans.pb('L');
					minn=arr[i];
				}
				else {
					break;
				}
			}
			break;
		}
		if (arr[l]<arr[r]) {
			ans.pb('L');
			minn=arr[l++];
		}
		else if (arr[r]<arr[l]) {
			ans.pb('R');
			minn=arr[r--];
		}
		else if (arr[l]==arr[r]) {
			vector<char> t1,t2;
			int premin=minn;
			for (int j=l;j<r;++j) {
				if (arr[j]>minn) {
					t1.pb('L');
					minn=arr[j];
				}
				else {
					break;
				}
			}
			minn=premin;
			for (int j=r;j>l;--j) {
				if (arr[j]>minn) {
					t2.pb('R');
					minn=arr[j];
				}
				else {
					break;
				}
			}
			if (t1.size()>=t2.size()) {
				ans.insert(ans.end(),t1.begin(),t1.end());
			}
			else {
				ans.insert(ans.end(),t2.begin(),t2.end());
			}
			break;
		}
	}
	if (l==r && arr[l]>minn) ans.pb('L');
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();++i) {
		cout<<ans[i];
	}
	return 0;
}
