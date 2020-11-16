#include <bits/stdc++.h>
using namespace std;
#define t first
#define c second
typedef long long ll;
typedef pair<int,int> pii;
int n,ans[200005];
pair<int,int>p[200005];
int fa[1200006];
int f(int x){if(x>1e6+n)x=1e6+n;return fa[x]==x?x:fa[x]=f(fa[x]);}
void merge(int x,int y){x=f(x),y=f(y);if(x!=y)fa[x]=y;}
bool check(int x)
{
	for(int i=1;i<=1e6+n;i++)fa[i]=i;
	for(int i=n-1;i>=0;i--)
	{
		ans[i]=f(p[i].t+x-p[i].c);
		if(ans[i]<p[i].t)return false;
		merge(ans[i],ans[i]-1);
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	int mid,l=0,r=1e9+n+1;
	for(int i=0;i<n;i++)
		scanf("%d%d",&p[i].t,&p[i].c),l=max(l,p[i].c);
	while(l<r)
	{
		mid=l+r>>1;
		if(check(mid)) r=mid; else l=mid+1;
	}
	//printf("%d\n",l);
	check(l);
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
	return 0;
}

/*
999999 1000002 1000000 1000001 1000003

5
999999 9
999999 8
1000000 11
1000000 10
1000000 8

99999
*/
