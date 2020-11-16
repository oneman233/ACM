#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
struct node
{
	ll a,b,w;
}o[100005];
vector<ll> rhy;
ll tr[300005];
int sum(int x)
{
	int ret=0;
	for(;x;x-=x&-x) ret+=tr[x];
	return ret;
}
void add(int x,int y)
{
	for(;x<=300000;x+=x&-x) tr[x]+=y;
}

bool cmp(node a,node b)
{
	if(a.a!=b.a) return a.a<b.a;
	else return a.b<b.b;
}

void gao()
{
	
}

int main()
{
	scanf("%d",&n);
	rhy.push_back(0ll);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&o[i].a,&o[i].b,&o[i].w);
		rhy.push_back(o[i].a);
		rhy.push_back(o[i].b);
		rhy.push_back(o[i].w);
	}
	sort(rhy.begin(),rhy.end());
	for(int i=1;i<=n;++i)
	{
		o[i].a=lower_bound(rhy.begin(),rhy.end(),o[i].a)-rhy.begin();
		o[i].b=lower_bound(rhy.begin(),rhy.end(),o[i].b)-rhy.begin();
		o[i].w=lower_bound(rhy.begin(),rhy.end(),o[i].w)-rhy.begin();
	}
	sort(o+1,o+1+n,cmp);
	gao();
	return 0;
}
