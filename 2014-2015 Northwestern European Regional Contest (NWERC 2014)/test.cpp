#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;

int n;
vector<int> e[N];
int a[N],b[N];
int fa[N];
set<int> s;

void dfs(int x,int f)
{
	fa[x]=f;
	for(auto y:e[x])
	{
		if(y==f) continue;
		dfs(y,x);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i],&b[i]);
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[fa[i]]||a[i]==b[fa[i]]) s.insert(a[i]);
		if(b[i]==b[fa[i]]||b[i]==a[fa[i]]) s.insert(b[i]);
	}
	printf("%d",(int)s.size());
	return 0;
}
/*
14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
7 11
7 12
7 13
7 14
4711 815
666 4711
4711 42
815 7
47 666
666 54
23 42
7 2
7 1
7 3
23 4
42 5
23 6
42 8

14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
7 11
7 12
7 13
7 14
999999999 999999998
999999997 999999998
999999996 999999998
999999994 999999998
999999997 999999998
999999997 999999998
999999995 999999996
999999994 999999998
999999994 999999998
999999994 999999998
999999995 999999996
999999995 999999996
999999995 999999996
999999995 999999996
*/
