#include <bits/stdc++.h>
using namespace std;
const int N=1005;

int p,k;
vector<int> v(N);
int sg[N];
bool vis[N];

void gao(int n)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		for(int j=0;j<=min(i,k);++j)
		{
			if(i==j) continue;
			int tmp=i-j-v[i-j];
			if(tmp>=0)
				vis[sg[tmp]]=1;
		}
		for(int j=0;;j++)
			if(!vis[j])
			{
				sg[i]=j;
				break;
			}
	}
}

int main()
{
	int ans=0;
	scanf("%d%d",&p,&k);
	for(int i=1,n;i<=p;++i)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;++j)
			scanf("%d",&v[j]);
		gao(n);
		ans^=sg[n];
	}
	if(ans==0) puts("Bob will win.");
	else puts("Alice can win.");
	return 0;
}

