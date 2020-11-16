#include <bits/stdc++.h>
using namespace std;
int n,b[100005],v[256];
int main()
{
	for(int i=0;i<256;i++)
		v[i^(i<<1)&0xff]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=1;i<=n;i++)
		printf("%d%c",v[b[i]]," \n"[i==n]);
	return 0;
}
