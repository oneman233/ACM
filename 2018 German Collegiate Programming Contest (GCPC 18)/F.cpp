#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n,a;
int f[100];
set<int> s;
map<int,int> mp;

int main()
{
	f[0]=1,f[1]=1;
	int i=2;
	s.insert(1);
	while(f[i-1]+f[i-2]<=1e6)
	{
		f[i]=f[i-1]+f[i-2];
		s.insert(f[i]);
		i++;
	}
	scanf("%d",&n);
	vector<int> p;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		if(s.count(a))
		{
			mp[a]=i;
		}
		if(a==1) p.push_back(i);
	}
	if(p.size()>=2)
	{
		printf("%d %d",p[0],p[1]);
		return 0;
	}
	for(int j=0;j<i;++j)
	{
		if(mp[f[j]]&&mp[f[j+1]]&&mp[f[j]]!=mp[f[j+1]])
		{
			printf("%d %d",mp[f[j]],mp[f[j+1]]);
			return 0;
		}
	}
	puts("impossible");
	return 0;
}
