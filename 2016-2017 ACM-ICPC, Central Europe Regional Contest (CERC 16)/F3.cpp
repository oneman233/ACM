#include <bits/stdc++.h>
using namespace std;

int n,fa1[100005],fa2[100005],d1[100005],d2[100005],c[100005],ans;

void gao(int now)
{
	if(fa1[now]==0) return;
	gao(fa1[now]);
	fa1[now]=0;
	ans++;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&fa1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&fa2[i]);
	for(int i=n;i;i--)
		if(fa1[i]!=fa2[i]) gao(i),gao(fa2[i]);
	for(int i=1;i<=n;i++)
		if(fa1[i]!=fa2[i]) ans++;
	printf("%d",ans);
	return 0;
}

/*
7
2 3 4 5 6 7 0
0 0 0 0 0 0 0

3
0 3 0
2 3 0
*/
