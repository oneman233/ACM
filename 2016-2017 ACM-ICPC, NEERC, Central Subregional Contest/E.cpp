#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mv[4][2]={1,0,0,1,-1,0,0,-1};
int h,w,cnt,a[305][305],b[305][305];
vector<pair<int,int>> ans;
bool flg;

bool ok(int x,int y,int dir)
{
	int dx=x+2*mv[dir][0]+2,dy=y+2*mv[dir][1]+2;
	if(a[dx][dy]) return true; else return false;
}

void dfs(int x,int y,int dir)
{
	ans.emplace_back(x,y);
	a[x+2][y+2]=0;
	cnt++;
	b[x+2][y+2]=cnt;
	b[x+3][y+2]=cnt;
	b[x+2][y+3]=cnt;
	b[x+3][y+3]=cnt;
	if(cnt==(h*w-3)/2) return;
	if(!ok(x,y,dir)) dir++,dir%=4; 
	dfs(x+mv[dir][0],y+mv[dir][1],dir);
}

void gao()
{
	if(h%2==1&&w%2==1)
	{
		memset(a,0,sizeof(a));
		for(int i=2;i<=h+2;i++)
			for(int j=2;j<=w+2;j++)
				a[i][j]=1;
		dfs(1,1,0);
		for(int i=3;i<=h+2;i++)
			for(int j=3;j<=w+2;j++)
				printf("%d%c",b[i][j]," \n"[j==w+2]);
		return;
	}
	ans.push_back({1,1});
	int x=2,y=1;
	while(1<=x&&x<=h&&1<=y&&y<=w)
	{
		if(x==h-1)
		{
			ans.push_back({x,y});
			ans.push_back({x,y+1});
			x=1,y+=2;
		}
		else
		{
			ans.push_back({x,y});
			x++;
		}
	}
	if(w%2==0||h%2==0) ans.pop_back();
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d%d",&h,&w);
	if(h==1||w==1) return puts("0"),0;
	if(h*w%2==1&&h>w)
	{
		swap(w,h);
		flg=1;
	}
	else if(h%2==0&&w%2==0&&h<w)
	{
		swap(w,h);
		flg=1;
	}
	else if(h%2==0&&w%2==1)
	{
		swap(w,h);
		flg=1;
	}
	//printf("! %d %d %d\n",h,w,flg);
	gao();
	printf("%d\n",(int)ans.size());
	for(auto &i:ans)
	{
		if(flg) swap(i.first,i.second);
		printf("%d %d\n",i.first,i.second);
	}
	return 0;
}
