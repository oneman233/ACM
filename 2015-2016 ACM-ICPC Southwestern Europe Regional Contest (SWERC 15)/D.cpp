#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> mp;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mp[i+j]++;
	int mx=-1;
	for(auto i=mp.begin();i!=mp.end();++i)
		mx=max(mx,i->second);
	for(auto i=mp.begin();i!=mp.end();++i)
		if(i->second==mx)
			printf("%d\n",i->first);
	return 0;
}
