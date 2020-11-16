#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int t,r,c;
vector<char> tmp,ans;
bool can=0,vis[15][15];

bool ok(int x,int y){
	if(x<1||x>12||y<1||y>12) return 0;
	if((x==6&&y==6)||
	(x==6&&y==7)||
	(x==7&&y==6)||
	(x==7&&y==7)||
	(x==9&&y==2)||
	(x==9&&y==3)||
	(x==9&&y==10)||
	(x==9&&y==11)||
	(x==10&&y==2)||
	(x==10&&y==11)||vis[x][y]){
		return 0;
	}
	return 1;
}

void dfs(int x,int y){
	if((x==3&&y==3)||(x==3&&y==10)||
	(x==10&&y==3)||(x==10&&y==10)){
		can=1;
		ans=tmp;
		return;
	}
	if(can) return;
	vis[x][y]=1;
	if(ok(x+1,y)){
		tmp.pb('D');
		dfs(x+1,y);
		tmp.pop_back();
	}
	if(ok(x,y+1)){
		tmp.pb('R');
		dfs(x,y+1);
		tmp.pop_back();
	}
	if(ok(x-1,y)){
		tmp.pb('U');
		dfs(x-1,y);
		tmp.pop_back();
	}
	if(ok(x,y-1)){
		tmp.pb('L');
		dfs(x,y-1);
		tmp.pop_back();
	}
	vis[x][y]=0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&r,&c);
		tmp.clear();
		ans.clear();
		memset(vis,0,sizeof(vis));
		can=0;
		dfs(r,c);
		printf("%d\n",(int)ans.size());
		for(auto i:ans) printf("%c",i);
		puts("");
	}
	return 0;
}
