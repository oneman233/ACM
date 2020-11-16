#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;

int n,m;
vector<string> A,T;
string s;
vector<int> e[205];
bool vis[205];
int match[205],rematch[205];

bool ok(string a,string b)
{
	int a1=0,a2=0,b1=0,b2=0;
	for(int i=0;i<3;++i) a1+=a[i]-'0';
	for(int i=3;i<6;++i) a2+=a[i]-'0';
	for(int i=0;i<3;++i) b1+=b[i]-'0';
	for(int i=3;i<6;++i) b2+=b[i]-'0';
	if(a1==b2||b1==a2) return 1;
	return 0;
}

bool ok2(string a,string b)
{
	int aa=a[0]+a[1]+a[2]-3*'0';
	int bb=b[3]+b[4]+b[5]-3*'0';
	return aa==bb;
}

bool dfs(int u)
{
	for(auto v:e[u])
	{
		if(!vis[v])
		{
			vis[v]=1;
			if(match[v]==0||dfs(match[v]))
			{
				match[v]=u;
				rematch[u]=v;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
//	FAST
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>s,A.push_back(s);
	for(int i=0;i<m;++i) cin>>s,T.push_back(s);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(ok(A[i],T[j]))
			{
				e[i+1].push_back(j+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ++ans;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)
	{
		if(rematch[i]==0) continue;
		if(ok2(A[i-1],T[rematch[i]-1])) cout<<"AT "<<A[i-1]<<' '<<T[rematch[i]-1]<<endl;
		else cout<<"TA "<<T[rematch[i]-1]<<' '<<A[i-1]<<endl;
	}
	return 0;
}
/*
2 2
123456 111222
141204 555000
*/
