#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,a[N],b[N],s1[N],s2[N],f[N];
int ans=0;

void gao(int x)
{
	int t=x;
	while(a[t]!=0) t=a[t];
	
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s1[a[i]]=i,f[i]=a[i];
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),s2[b[i]]=i;
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])
			gao(i);
	printf("%d",ans);
	return 0;
}
/*
7
2 3 4 5 6 7 0
0 0 0 0 0 0 0
*/
