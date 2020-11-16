#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int a,b,ans=0;
int cnt[1000],mx1[1000],mx2[1000];
set<vector<int>> s;

bool ok()
{
	mx1[0]=-0x3f3f3f3f;
	mx2[a+1]=-0x3f3f3f3f;
	for(int i=1;i<=a;++i) mx1[i]=max(mx1[i-1],cnt[i]);
	for(int i=a;i>=1;--i) mx2[i]=max(mx2[i+1],cnt[i]);
	for(int i=1;i<=a;++i)
	{
		if(mx1[i-1]>cnt[i]&&mx2[i+1]>cnt[i]) return 0;
	}
	return 1;
}

void dfs(int pos,int rem)
{
	if(rem==0)
	{
		if(ok()){
			vector<int> v;
			for(int i=1;i<=a;++i) v.push_back(cnt[i]);
			s.insert(v);
		}
		return;
	}
	cnt[pos]++;
	for(int i=1;i<=a;++i) dfs(i,rem-1);
	cnt[pos]--;
}

int main()
{
	while(~scanf("%d%d",&a,&b))
	{
		s.clear();
		for(int i=1;i<=a;++i) cnt[i]=1;
		b-=a;
		for(int i=1;i<=a;++i) dfs(i,b);
		printf("%d\n",(int)s.size());
	}
	return 0;
}
