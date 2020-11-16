#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int inf=0x3f3f3f3f;

int t,k,g[5][5];
int s(int i,int j){
	return g[i][j]+g[i+1][j]+g[i][j+1]+g[i+1][j+1];
}
void roll(int i,int j){
	int a=g[i][j];
	int b=g[i][j+1];
	int c=g[i+1][j];
	int d=g[i+1][j+1];
	g[i][j]=b;
	g[i][j+1]=d;
	g[i+1][j]=a;
	g[i+1][j+1]=c; 
}
void reroll(int i,int j){
	int a=g[i][j];
	int b=g[i][j+1];
	int c=g[i+1][j];
	int d=g[i+1][j+1];
	g[i][j]=c;
	g[i][j+1]=a;
	g[i+1][j]=d;
	g[i+1][j+1]=b; 
}

int dfs(int k,int who){
	int mx=-inf,mn=inf;
	if(k==1){
		re(i,1,3){
			re(j,1,3){
				mx=max(mx,s(i,j));
				mn=min(mn,s(i,j));
			}
		}
		if(who==1) return mx;
		else return mn;
	}
	re(i,1,3){
		re(j,1,3){
			int t1=s(i,j);
			roll(i,j);
			int t2=dfs(k-1,who^1);
			reroll(i,j);
			mx=max(mx,t2+t1);
			mn=min(mn,t2+t1);
		}
	}
	if(who==1) return mx;
	else return mn;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				scanf("%d",&g[i][j]);
		int ans=dfs(2*k,1);
		printf("%d\n",ans);
	}
	return 0;
}
