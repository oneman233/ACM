#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,fa[N];

void gao()
{
	
}

int main()
{
	freopen("hidden.in","r",stdin);
	freopen("hidden.out","w",stdout);
	scanf("%d",&n);
	fa[1]=1;
	for(int i=2,tmp;i<=n;++i)
	{
		scanf("%d",&tmp);
		fa[i]=tmp;
	}
	gao();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
