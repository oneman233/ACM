#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,l[500005],r[500005],state[500005],in[500005],vis[500005];
ll ball[500005];
char op[10];

int main()
{
	scanf("%lld%d",&ball[1],&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%s%d%d",op,l+i,r+i);
		if(op[0]=='R') state[i]=1; else state[i]=0;
		in[l[i]]++,in[r[i]]++;
	}
	queue<int> q;
	for(int i=1;i<=m;i++) if(in[i]==0) q.push(i),vis[i]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		ll rc=ball[now]/2,lc=ball[now]-rc;
		if(state[now])
			ball[l[now]]+=rc,ball[r[now]]+=lc;
		else
			ball[r[now]]+=rc,ball[l[now]]+=lc;
		state[now]^=(ball[now]&1);
		in[l[now]]--,in[r[now]]--;
		ball[now]=0;
		if(!vis[l[now]]&&in[l[now]]==0) q.push(l[now]),vis[l[now]]++;
		if(!vis[r[now]]&&in[r[now]]==0) q.push(r[now]),vis[r[now]]++;
	}
	assert(ball[0]==n);
	for(int i=1;i<=m;i++) printf("%c","LR"[state[i]]);
	return 0;	
}
/*
101 2
L 2 2
R 0 0

1 4
L 2 2
R 3 4
L 0 0
R 0 0
*/
