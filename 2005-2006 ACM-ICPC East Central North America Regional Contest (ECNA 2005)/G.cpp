#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int Case=1,x[1005],y[1005];
map<pair<int,int>,int> mp;

int main()
{
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
		int mx=-1;
		for(int i=1;i<=n;++i)
		{
			mp.clear();
			for(int j=1;j<=n;++j)
			{
				if(i==j) continue;
				if(x[i]==x[j])
				{
					mp[{1e9,1e9}]++;
					mx=max(mx,mp[{1e9,1e9}]+1);
				}
				else
				{
					int Y=y[j]-y[i],X=x[j]-x[i];
					mp[{X/__gcd(X,Y),Y/__gcd(X,Y)}]++;
					mx=max(mx,mp[{X/__gcd(X,Y),Y/__gcd(X,Y)}]+1);
				}
			}
		}
		printf("Photo %d: %d points eliminated\n",Case,(mx<4?0:mx));
		Case++;
	}
	return 0;
}
