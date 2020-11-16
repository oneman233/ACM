#include <bits/stdc++.h>
using namespace std;

int n,m;
char mp[1005][1005];
char s[1005];
int ans=0;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",mp[i]+1);
	if(n==1&&m==1){
		printf("0");
		return 0;
	}
//	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) printf("%c%c",mp[i][j]," \n"[j==m]);
	if(n==1){
		for(int j=2;j<=m-1;++j)
			if(mp[1][j]=='.') ++ans;
		printf("%d",ans);
		return 0;
	}
	if(m==1){
		for(int j=2;j<=n-1;++j)
			if(mp[j][1]=='.') ++ans;
		printf("%d",ans);
		return 0;
	}
	if(n==2){
		for(int i=2;i<=m-1;++i)
			if(mp[1][i]=='.'&&mp[2][i]=='.') ++ans;
		printf("%d",ans);
		return 0;
	}
	if(m==2){
		for(int i=2;i<=n-1;++i)
			if(mp[i][1]=='.'&&mp[i][2]=='.') ++ans;
		printf("%d",ans);
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m)) continue;
			if(mp[i][j]=='.'&&i!=1&&i!=n&&j!=1&&j!=m) ++ans;
			if(mp[i][j]=='#'&&(i==1||i==n||j==1||j==m)) ++cnt;
		}
	}
	if(cnt==0) ++ans;
	printf("%d",ans);
	return 0;
}
