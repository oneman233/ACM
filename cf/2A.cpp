#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;

int mx=0;
int n,s[maxn];
string name[maxn],ans;
map<string,int> mp,mp2;

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>name[i]>>s[i];
		mp[name[i]]+=s[i];
	}
	for(auto i=mp.begin();i!=mp.end();++i)
		mx=max(mx,i->second);
	for(int i=1;i<=n;++i)
	{
		mp2[name[i]]+=s[i];
		if(mp[name[i]]==mx&&mp2[name[i]]>=mx)
		{
			ans=name[i];
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
a 1000
b 10
a -990
*/
