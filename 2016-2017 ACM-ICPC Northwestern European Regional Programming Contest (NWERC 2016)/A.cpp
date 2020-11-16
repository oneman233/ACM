#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
const int N=45;

int n,m;
string s[N];
string dp[N][N*2];
int pre[N][N*2];
bool can[N][N*2];

bool gao(string &p,string s,string t,int k)
{
	p=s;
	int cnt=k,i=0;
	for(;i<m&&cnt>0;++i)
	{
		if(p[i]!=t[i])
		{
			p[i]=t[i];
			cnt--;
		}
	}
	if(p>=t) return 1;
	for(--i;i>=0&&p[i]=='9';--i);//
	if(i<0) return 0;
	p=s;
	cnt=k;
	for(int j=0;j<i;++j)
	{
		if(p[j]!=t[j])
		{
			p[j]=t[j];
			cnt--;
		}
	}
	if(p[i]!=t[i]+1)
	{
		p[i]=t[i]+1;
		cnt--;
	}
	for(int j=i+1;j<m&&cnt>0;++j)
	{
		p[j]='0';
		cnt--;
	}
	return 1;
}

void gao2()
{
	can[0][0]=1;
	for(int i=0;i<m;++i)
		dp[0][0]+='0';
}

int main()
{
	FAST
	cin>>n>>m;for(int i=1;i<=n;++i) cin>>s[i];
	gao2();
	for(int i=0;i+1<=n;++i)
	{
		for(int j=0;j<=2*n;++j)
		{
			if(!can[i][j]) continue;
			string p=s[i+1];
			for(int k=0;j+k<=2*n;++k)
			{
				if(gao(p,s[i+1],dp[i][j],k)&&(!can[i+1][j+k]||dp[i+1][j+k]>p))
				{
					can[i+1][j+k]=1;
					pre[i+1][j+k]=j;
					dp[i+1][j+k]=p;
				}
			}
		}
	}
	stack<string> ans;
	for(int j=0;j<=2*n;++j)
	{
		if(can[n][j])
		{
			for(int i=n;i>=1;--i)
			{
				ans.push(dp[i][j]);
				j=pre[i][j];
			}
			break;
		}
	}
	while(!ans.empty())
	{
		cout<<ans.top()<<endl;
		ans.pop();
	}
	return 0;
}
/*
5 3
111
001
000
111
000
*/
