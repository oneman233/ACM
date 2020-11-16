#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e7+5;

int n;
bool isp[N];
vector<int> p;

void gao()
{
	isp[1]=0;
	for(int i=2;i<=1e7+1e6;++i)
	{
		if(!isp[i]) p.push_back(i);
		for(int j=0;j<p.size();++j)
		{
			if(i*p[j]>1e7+1e6) break;
			isp[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}

map<int,int> mp;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	gao();
//	for(auto i:p) cout<<i<<endl;
	int cnt=0;
	for(int i=0;i<p.size();++i)
	{
		while(n%p[i]==0)
		{
			mp[p[i]]++;
			cnt++;
			n/=p[i];
		}
	}
	if(mp.size()==3&&cnt==3) puts("YES");
	else puts("NO");
	return 0;
}
