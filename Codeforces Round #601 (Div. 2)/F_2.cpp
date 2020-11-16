#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct node
{
	int x,y;ll w;
};
int n;
ll dp[200005],bit[200005];
map<pii,ll> mp;
vector<int> a,b;
vector<node> v;

inline bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

ll query(int x)
{
	ll ret=0;
	for(;x;x-=x&-x) ret=max(ret,bit[x]);
	return ret;
}

void modify(int x,ll y)
{
	for(;x<=200000;x+=x&-x) bit[x]=max(bit[x],y);
}

int main()
{
	scanf("%d",&n);
	for(int i=0,x,y,w;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		a.push_back(x),b.push_back(y);
		mp[{x,y}]+=w;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(auto p:mp)
	{
		int a1=lower_bound(a.begin(),a.end(),p.first.first)-a.begin()+1;
		int b1=lower_bound(b.begin(),b.end(),p.first.second)-b.begin()+1;
		v.push_back({a1,b1,p.second});
	}
	sort(v.begin(),v.end(),cmp);
	ll ans=0;
	for(int i=0;i<v.size();i++)
	{
		if(i&&v[i].x!=v[i-1].x)
		{
			int j=i-1;
			do
			{
				modify(v[j].y,dp[j]);
				j--;
			}while(j>=0&&v[j+1].x==v[j].x);
		}
		dp[i]=query(v[i].y-1)+v[i].w;
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}
