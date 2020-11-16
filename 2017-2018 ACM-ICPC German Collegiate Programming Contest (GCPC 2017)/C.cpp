#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;

int x,n,m,T;
vector<int> e[N];
int dp[N][N];
int t[N],p[N];
bool v[N];

void bfs(){
	queue<int> q;
	q.push(1);
	v[1]=1;
	while(!q.empty()){
		int f=q.front();q.pop();
		v[f]=0;
		for(int i=t[1];i<=x;++i){
			if(dp[f][i]==0x3f3f3f3f) continue;
			for(auto y:e[f]){
				if(i+T+t[y]>x) continue;
				if(dp[y][i+T+t[y]]>dp[f][i]+p[y]){
					dp[y][i+T+t[y]]=dp[f][i]+p[y];
					if(!v[y]) q.push(y),v[y]=1;
				}
			}
			if(i+t[f]<=x){
				if(dp[f][i+t[f]]>dp[f][i]+p[f]){
					dp[f][i+t[f]]=dp[f][i]+p[f];
					if(!v[f]) q.push(f),v[f]=1;
				}
			}
		}
	}
}

void gao(){
	if(t[1]*2>x){
		puts("It is a trap.");
		return;
	}
	if(t[1]*2==x){
		printf("%d",p[1]*2);
		return;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][t[1]]=p[1];
	bfs();
	if(dp[1][x]==0x3f3f3f3f) puts("It is a trap.");
	else printf("%d",dp[1][x]);
}

int main()
{
	scanf("%d%d%d%d",&x,&n,&m,&T);
	for(int i=1,a,b;i<=m;++i){
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=n;++i)
		scanf("%d%d",&t[i],&p[i]);
	gao();
	return 0;
}
/*
6
4 4 1
1 2
2 3
3 4
4 1
1 2
2 1
5 4
3 3
*/
