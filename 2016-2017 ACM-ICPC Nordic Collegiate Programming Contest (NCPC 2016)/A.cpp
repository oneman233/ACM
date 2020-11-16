#include <bits/stdc++.h>
using namespace std;
const int maxn=2000005;

int n,m,q;
int x1[10005],y1[10005],x2[10005],y2[10005];
int ans[10005],f[maxn];
int mp[1005][1005];

int h(int x,int y){
	return x*m+y;
}
int _find(int x){
	if(f[x]!=x) f[x]=_find(f[x]);
	return f[x];
}
int _merge(int x,int y){
	x=_find(x),y=_find(y);
	if(x!=y) f[x]=y;
}

bool ok(int x,int y){
	if(x<1||x>n||y<1||y>m) return 0;
	return 1;
}

void gao(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			f[h(i,j)]=h(i,j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(mp[i][j]==0){
				if(ok(i+1,j)&&mp[i+1][j]==0)
					_merge(h(i,j),h(i+1,j));
				if(ok(i-1,j)&&mp[i-1][j]==0)
					_merge(h(i,j),h(i-1,j));
				if(ok(i,j+1)&&mp[i][j+1]==0)
					_merge(h(i,j),h(i,j+1));
				if(ok(i,j-1)&&mp[i][j-1]==0)
					_merge(h(i,j),h(i,j-1));
			}
		}
	}
	map<int,int> cnt;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(mp[i][j]==0){
				cnt[_find(h(i,j))]=1;
			}
		}
	}
	ans[q]=cnt.size();
	int now=cnt.size();
	for(int i=q;i>=1;--i){
		for(int x=x1[i];x<=x2[i];++x){
			for(int y=y1[i];y<=y2[i];++y){
				mp[x][y]--;
				if(mp[x][y]==0){
					now++;
					if(ok(x+1,y)&&mp[x+1][y]==0&&_find(h(x,y))!=_find(h(x+1,y)))
						_merge(h(x,y),h(x+1,y)),now--;
					if(ok(x-1,y)&&mp[x-1][y]==0&&_find(h(x,y))!=_find(h(x-1,y)))
						_merge(h(x,y),h(x-1,y)),now--;
					if(ok(x,y+1)&&mp[x][y+1]==0&&_find(h(x,y))!=_find(h(x,y+1)))
						_merge(h(x,y),h(x,y+1)),now--;
					if(ok(x,y-1)&&mp[x][y-1]==0&&_find(h(x,y))!=_find(h(x,y-1)))
						_merge(h(x,y),h(x,y-1)),now--;
//					if(now<=0) now=1;
				}
			}
		}
		ans[i-1]=now;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=q;++i){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		for(int x=x1[i];x<=x2[i];++x)
			for(int y=y1[i];y<=y2[i];++y)
				mp[x][y]++;
	}
	gao();
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}
/*
4 6 5
2 2 2 6
1 3 4 3
2 5 3 5
4 6 4 6
1 6 4 6
*/
