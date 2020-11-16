#include <bits/stdc++.h>
using namespace std;
const int N=1505;

int m,n,k;
int match[N],tmp[N];
bool v[N],mp[3*N][3*N];

bool dfs(int x){
	for(int y=1;y<=n;++y){
		if(!mp[x][y]) continue;
		if(!v[y]){
			v[y]=1;
			if(match[y]==0||dfs(match[y])){
				match[y]=x;
				return 1;
			}
		}
	}
	return 0;
}

void gao(){
	int now=0;
	for(int i=1;i<=m;++i){
		memset(v,0,sizeof(v));
		if(dfs(i)) ++now;
	}
//	cout<<now<<endl;
	int ans=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)
			tmp[j]=match[j];
		for(int j=1;j<=n;++j)
			if(mp[i][j]) mp[i+m][j]=mp[i+2*m][j]=1;
		int cnt=0;
		memset(v,0,sizeof(v));
		if(dfs(i+m)) cnt++;
		memset(v,0,sizeof(v));
		if(dfs(i+2*m)) cnt++;
		ans=max(ans,cnt);
		for(int j=1;j<=n;++j)
			if(mp[i][j]) mp[i+m][j]=mp[i+2*m][j]=0;
		for(int j=1;j<=n;++j)
			match[j]=tmp[j];
	}
	printf("%d",now+ans);
}

int main(){
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1,x,y;i<=k;++i){
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}
	gao();
	return 0;
}

