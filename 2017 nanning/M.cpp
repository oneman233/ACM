#include <bits/stdc++.h>
using namespace std;

int t,n,m,u,v;
int g[105][105];
bool vis[105];
int lk[105];

void floyd(){
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
}

bool dfs(int x){
	for(int i=1;i<=n;++i){
		if(g[x][i]==1&&!vis[i]){
			vis[i]=1;
			if(lk[i]==0||dfs(lk[i])){
				lk[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		memset(lk,0,sizeof(lk));
		for(int i=1;i<=m;++i){
			scanf("%d%d",&u,&v);
			g[u][v]=1;
		}
		floyd();
//		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<g[i][j]<<" \n"[j==n];
		int ans=0;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ++ans;	
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
