#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n;
vector<pii> ans;
int cnt[1005];
bool vis[1005];

int main()
{
	scanf("%d",&n);
	bool can=1;
	for(int i=1,a,b;i<=n-1;++i)
	{
		scanf("%d%d",&a,&b);
		if(b==n) cnt[a]++;
		else can=0;
	}
	if(!can) puts("NO");
	else
	{
		vis[n]=1;
		for(int i=1;i<=n;++i)
		{
			int p=1,pre=i;
			if(cnt[i]==0) continue;
			vis[i]=1;
			while(cnt[i]>1)
			{
				while(vis[p]&&p<i) p++;
				if(vis[p])
				{
					can=0;
					break;
				}
				ans.emplace_back(pre,p);
				vis[pre]=vis[p]=1;
				pre=p;
				cnt[i]--;
			}
			if(!can) break;
			//if(cnt[i]==1)
			ans.emplace_back(pre,n);
			vis[pre]=1;
		}
		for(int i=1;i<=n;++i)
			if(!vis[i])
				can=0;
		if(can)
		{
			puts("YES");
			for(auto i:ans) printf("%d %d\n",i.first,i.second);
		}
		else puts("NO");
	}
	return 0;
}
/*
4
1 4
3 4
3 4
*/
