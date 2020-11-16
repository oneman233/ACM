#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,d,tot,ans[200005];
pii a[200005];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0,x;i<n;i++)
	{
		scanf("%d",&x);
		a[i]={x,i};
	}
	sort(a,a+n);
	for(int i=0,x,y;i<n;i++)
	{
		x=a[i].first,y=a[i].second;
		if(!q.empty()&&x>q.top().first+d) 
		{
			ans[y]=q.top().second;
			q.pop();
			q.emplace(x,ans[y]);
		}
		else tot++,q.emplace(x,tot),ans[y]=tot;
	}
	printf("%d\n",tot);
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	return 0;
}
