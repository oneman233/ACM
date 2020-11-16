#include <bits/stdc++.h>
using namespace std;

int n,fa1[100005],fa2[100005],d1[100005],d2[100005],c[100005];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&fa1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&fa2[i]);
	d1[0]=d2[0]=-1;
	for(int i=n;i;i--)
	{
		if(c[fa1[i]])
			d1[i]=d2[i]=1;
		else
			d1[i]=d1[fa1[i]]+1,d2[i]=d2[fa2[i]]+1;
		if(fa1[i]!=fa2[i]) c[i]=1;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=d1[i]+(c[i]?d2[i]:0),printf("! %d %d %d\n",i,d1[i],d2[i]);
	printf("%lld",ans);
	return 0;
}

/*
7
2 3 4 5 6 7 0
0 0 0 0 0 0 0
*/
