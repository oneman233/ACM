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
const ll mod = 998244353;
 
struct node{
	int x,y;
}uu[maxn];
 
bool cmp1(node a,node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
int pai[maxn];
 
signed main()
{
	pai[1] = 1;
	for(int i=2;i<4e5;i++) pai[i] = pai[i-1]*i%mod;
	int n;
	rd(n);
	for(int i=0;i<n;i++) rd(uu[i].x),rd(uu[i].y);
	sort(uu,uu+n,cmp1);
	int ans = 0;
	int as = 1;
	for(int i=1;i<n;i++)
	{
		int tmp = 0;
		while(i<n&&uu[i].x==uu[i-1].x){
			tmp++;i++;
		}
		if(tmp) as=(as*pai[tmp+1])%mod;
		//pt(ans,'\n');
		if(tmp) i--;
	}
	ans=(ans+as)%mod;
	int fg = 1;
	for(int i=1;i<n;i++){
		if(uu[i].y<uu[i-1].y){
			fg= 0;
			break;
		}
	}
	
	if(fg)
	{
		as=1;
		for(int i=1;i<n;i++)
		{
			int tmp = 0;
			while(i<n&&uu[i].x==uu[i-1].x&&uu[i].y==uu[i-1].y){
				tmp++;i++;
			}
			if(tmp) as=(as*pai[tmp+1])%mod;
		//	pt(ans,'\n');
			if(tmp) i--;
		}
		ans=(ans-as)%mod;
	}
	sort(uu,uu+n,cmp2);
	as=1;
	for(int i=1;i<n;i++)
	{
		int tmp = 0;
		while(i<n&&uu[i].y==uu[i-1].y){
			tmp++;i++;
		}
		if(tmp) as=(as*pai[tmp+1])%mod;
		if(tmp) i--;
	}
	ans=(ans+as)%mod;
	ans = ((pai[n]-ans)%mod+mod)%mod;
	pt(ans);
	return 0;
}
