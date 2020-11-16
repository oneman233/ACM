#include <bits/stdc++.h>
using namespace std;

string s;
set<string>ss;
map<string ,int> c, c2;

int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i)
		cin>>s, ++c[s], ss.insert(s);
	for(int i=0;i<n;++i)
		cin>>s, ++c2[s], ss.insert(s);
	int ans=0;
	for(auto sss:ss)
		ans+=min(c[sss],c2[sss]);
//	int ans=min(c['c'],c2['c']);
//	ans+=min(c['w'],c2['w']);
//	ans+=min(c['t'],c2['t']);
	printf("%d",ans);
	return 0;	
}
