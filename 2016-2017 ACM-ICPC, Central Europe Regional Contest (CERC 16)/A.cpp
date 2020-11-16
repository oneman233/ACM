#include <bits/stdc++.h>
using namespace std;
const int N=115;

int r,c,a=0,b=0,cnt=1;
char mp[N][N];
char s[N];
char us[4030][N][N];
char tmp[N][N],tmp2[N][N];

bool gao3(char x[N][N],char y[N][N]){
	bool ret=1;
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			if(x[i][j]!=y[i][j]){
				ret=0;
				break;
			}
	return ret;
}

bool gao2(int x,int y){
	if(a!=b){
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=us[x][a-i+1][b-j+1];
		if(gao3(tmp,us[y])) return 1;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=us[x][i][j];
		if(gao3(tmp,us[y])) return 1;
	}
	else{
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=tmp2[i][j]=us[x][i][j];
		if(gao3(tmp,us[y])) return 1;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp2[j][a-i+1]=tmp[i][j];
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=tmp2[i][j];
		if(gao3(tmp,us[y])) return 1;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp2[j][a-i+1]=tmp[i][j];
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=tmp2[i][j];
		if(gao3(tmp,us[y])) return 1;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp2[j][a-i+1]=tmp[i][j];
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				tmp[i][j]=tmp2[i][j];
		if(gao3(tmp,us[y])) return 1;
	}
	return 0;
}

void gao(){
	int ans=0;
	for(int i=1;i<cnt;++i){
		bool add=1;
		for(int j=1;j<i;++j){
			if(gao2(j,i)){
				add=0;
				break;
			}
		}
		if(add) ans++;
	}
	printf("%d",ans);
}

int main()
{
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i){
		scanf("%s",s+1);
		for(int j=1;j<=c;++j)
			mp[i][j]=s[j];
	}
	for(int j=2;j<=c;++j){
		if(mp[2][j]=='#') break;
		b++;
	}
	for(int i=2;i<=r;++i){
		if(mp[i][2]=='#') break;
		a++;
	}
	int x=2,y=2;
	while(x<=r&&y<=c){
		for(int i=x;i<x+a;++i)
			for(int j=y;j<y+b;++j)
				us[cnt][i-x+1][j-y+1]=mp[i][j];
		cnt++;
		y+=b+1;
		if(y>c){
			y=2;
			x+=a+1;
		}
	}
	gao();
	return 0;
}
