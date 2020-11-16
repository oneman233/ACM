#include <bits/stdc++.h>
using namespace std;

int n,q;
int r[100005],c[100005];
int sr[100005],sc[100005];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&r[i]),sr[i]=sr[i-1]+(r[i]&1);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]),sc[i]=sc[i-1]+(c[i]&1);
	while(q--)
	{
		int x1,y1,x2,y2,f=1;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2) swap(x1,x2);if(y1>y2) swap(y1,y2);
		if(r[x1]%2==1&&sr[x2]-sr[x1-1]!=x2-x1+1) f=0;
		if(r[x1]%2==0&&sr[x2]-sr[x1-1]!=0) f=0;
		if(c[y1]%2==1&&sc[y2]-sc[y1-1]!=y2-y1+1) f=0;
		if(c[y1]%2==0&&sc[y2]-sc[y1-1]!=0) f=0;
		//printf("! %d %d\n",sr[x2]-sr[x1-1],sc[y2]-sc[y1-1]);
		if(f) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}
