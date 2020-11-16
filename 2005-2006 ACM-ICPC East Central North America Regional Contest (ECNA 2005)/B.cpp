#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,d,t;
vector<int> e[1005];
map<string,int> mpsi;
map<int,string> mpis;
string s1,s2;
int cnt=0;
vector<pair<int,int>> ans;

int dfs(int x,int dep)
{
	if(dep==0) return 1;
	int ret=0;
	for(auto i:e[x])
		ret+=dfs(i,dep-1);
	return ret;
}

bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first!=b.first) return a.first>b.first;
	else return mpis[a.second]<mpis[b.second];
}

void gao(int Case)
{
	cin>>n>>d;
	for(int i=1;i<=1000;++i) e[i].clear();
	mpsi.clear();mpis.clear();ans.clear();
	cnt=0;
	for(int i=1,k;i<=n;++i)
	{
		cin>>s1>>k;
		if(!mpsi[s1]) mpsi[s1]=++cnt,mpis[cnt]=s1;
		for(int j=1;j<=k;++j)
		{
			cin>>s2;
			if(!mpsi[s2]) mpsi[s2]=++cnt,mpis[cnt]=s2;
			e[mpsi[s1]].push_back(mpsi[s2]);
		}
	}
	for(int i=1;i<=cnt;++i)
		ans.push_back({dfs(i,d),i});
	sort(ans.begin(),ans.end(),cmp);
	cout<<"Tree "<<Case<<":\n";
	int last=1e9,cc=0;
	for(auto i:ans)
	{
		if(i.first>0&&(cc<3||i.first==last))
		{
			if(cc<3) last=i.first;
			cc++;
			cout<<mpis[i.second]<<' '<<i.first<<'\n';
		}
	}
	cout<<'\n';
}

int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
		gao(i);
	return 0;
}
