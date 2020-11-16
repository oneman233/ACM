#include <bits/stdc++.h>
using namespace std;

int n,a[1005];
map<int,int> mp;
vector<int> ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int cnt=0;
	bool can=1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>0)
		{
			mp[a[i]]++;
		}
		else if(a[i]<0)
		{
			if(mp[-a[i]]>0) mp[-a[i]]--;
			else
			{
				if(cnt==0)
				{
					can=0;
					break;
				}
				else
				{
					cnt--;
					ans.push_back(-a[i]);
				}
			}
		}
		else cnt++;
	}
	if(!can) puts("No");
	else
	{
		while(cnt--) ans.push_back(1);
		puts("Yes");
		for(auto i:ans) printf("%d ",i);
	}
	return 0;
}
