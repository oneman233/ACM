#include <bits/stdc++.h>
using namespace std;

int q,n,m;

struct ques
{
	char pass;
	int cnt,t;
	void read()
	{
		cin>>pass>>cnt>>t;
	}
}

struct node
{
	int pass_ques,
	string name;
	ques q[25];
	void read()
	{
		cin>>name;
		for(int i=1;i<=n;++i)
			q[i].read();
		for(int i=1;i<=n;++i)
		{
			
		}
	}
}people[1005],use[1005];

bool cmp(node a,node b)
{
	
}

void gao()
{
	
}

int main()
{
	cin>>q>>n>>m;
	for(int i=1;i<=n;++i)
	{
		people[i].read();
	}
	for(int i=1;i<=m;++i)
	{
		ues[i].read();
	}
	gao();
	return 0;
}
