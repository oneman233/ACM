#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pr;
#define mpr make_pair
#define int ll
#define case int ___T; scanf("%d", &___T); for(int cas=1;cas<=___T;cas++)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
const ll INF = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
const ll maxn = 1e6+5;
const ll maxm = 1e7;
const ll mod = 1e9+7;
 
int uu[maxn],uh[maxn],ans[maxn];
 
signed main()
{
	for(int i=0;i<4;i++) rd(uh[i]),uu[i]=uh[i];
	int cnt = 0;
	for(int i=0;i<1;i++){
		while(uu[i]&&uu[i+1]){
			ans[cnt++]=i;
			ans[cnt++]=i+1;
			uu[i]--;uu[i+1]--;
		}
	}
	for(int i=2;i<3;i++){
		while(uu[i]&&uu[i+1]){
			ans[cnt++]=i;
			ans[cnt++]=i+1;
			uu[i]--;uu[i+1]--;
		}
	}
	for(int i=1;i<2;i++){
		while(uu[i]&&uu[i+1]){
			ans[cnt++]=i+1;
			ans[cnt++]=i;
			uu[i]--;uu[i+1]--;
		}
	}
	for(int i=0;i<4;i++) if(uu[i]) ans[cnt++]=i,uu[i]--;
	int fg = 0;
	for(int i=0;i<4;i++) if(uu[i]){
		fg = 1;
	}
	for(int i=0;i<cnt-1;i++)
		if(abs(ans[i]-ans[i+1])!=1) fg=1;
	if(fg)
	{
		fg = 0;cnt=0;
		for(int i=2;i<3;i++){
		while(uh[i]&&uh[i+1]){
				ans[cnt++]=i+1;
				ans[cnt++]=i;
				uh[i]--;uh[i+1]--;
			}
		}
		for(int i=0;i<1;i++){
			while(uh[i]&&uh[i+1]){
				ans[cnt++]=i+1;
				ans[cnt++]=i;
				uh[i]--;uh[i+1]--;
			}
		}
		for(int i=1;i<2;i++){
			while(uh[i]&&uh[i+1]){
				ans[cnt++]=i;
				ans[cnt++]=i+1;
				uh[i]--;uh[i+1]--;
			}
		}
		for(int i=0;i<4;i++) if(uh[i]) ans[cnt++]=i,uh[i]--;
		for(int i=0;i<4;i++) if(uh[i]){
			fg = 1;
		}
		for(int i=0;i<cnt-1;i++)
			if(abs(ans[i]-ans[i+1])!=1) fg=1;
	}
	if(fg) cout<<"NO";
	else{
		cout<<"YES"<<endl;
		for(int i=0;i<cnt;i++)
			cout<<ans[i]<<" ";
	}
	return 0;
}
