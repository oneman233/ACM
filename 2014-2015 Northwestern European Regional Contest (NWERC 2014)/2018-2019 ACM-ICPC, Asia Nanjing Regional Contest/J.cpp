#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;

int n,a[N];
bool vis[N];
ll sum;
vector<int> p[1000005],g[1000005];

void gao()
{
	for(int i=2;i<=1000000;++i)
		if(!vis[i])
		{
			for(int j=i;j<=1000000;j+=i) 
				vis[j]=1,p[j].push_back(i);
		}
}

int main()
{
	gao();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for(auto pp:p[a[i]])
			g[pp].push_back(i);
	}
	for(int i=1;i<=1000000;i++)
	{
		if(g[i].size()==0) continue;
		for(int j=0;j<g[i].size()-1;j++)
			sum+=((long long)g[i][j+1]-g[i][j])*g[i][j];
		sum+=((long long)n-g[i][g[i].size()-1]+1)*g[i][g[i].size()-1];
	}
	printf("%lld",sum);
	return 0;
}
