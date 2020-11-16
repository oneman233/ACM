#include <bits/stdc++.h>
using namespace std;

int n,m;
int r[505][1005],c[505][1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<2*m;j+=2)
			scanf("%d%d",&r[i][j],&c[i][j]);
	
	return 0;
}
