#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1005],b[1005],ans;
bool ok()
{
	for(int i=1;i<=n;i++)
		if(a[i]+ans>b[i])
			return true;
		else if(a[i]+ans<b[i])
			return false;
	return true;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",a+i);for(int i=1;i<=n;i++)scanf("%d",b+i);
	while(!ok())
		++ans;
	printf("%d\n",ans);
	return 0;
}
