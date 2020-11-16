#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k,n,s[10005];
map<int,int> cnt;
vector<pair<int,int>> v;
int a=-1,_a=-1;

int main()
{
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;++i) scanf("%d",&s[i]),cnt[s[i]]++;
	for(int i=1;i<=k;++i) v.emplace_back(cnt[i],i);
	sort(v.begin(),v.end());
	if(cnt[v[0].second]!=cnt[v[1].second])
	{
		cnt[v[0].second]++;
		a=v[0].second;
	}
	int sz=v.size();
	if(cnt[v[sz-1].second]!=cnt[v[sz-2].second])
	{
		cnt[v[sz-1].second]--;
		_a=v[sz-1].second;
	}
	bool can=1;
	int all=cnt[1];
	for(int i=1;i<=k;++i)
	{
		if(cnt[i]!=all)
		{
			can=0;
			break;
		}
	}
	if(!can) return puts("*"),0;
	if(_a!=-1) printf("-%d ",_a);
	if(a!=-1) printf("+%d",a);
	return 0;
}
