#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,p=-1;
ll k,mx=-1,a[100005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%lld",&n,&k);
	ll sum=0;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),sum+=a[i];
	for(int i=1;i<=n;++i)
	{
		if(a[i]>mx)
		{
			mx=a[i];
			p=i;
		}
	}
	ll pre=0;
	for(int i=1;i<p;++i) pre+=a[i];
	bool can=0;
	ll L=p-1,R=pre;
	while(L<=k)
	{
//		cout<<L<<' '<<R<<endl;
		if(L<=k&&k<=R)
		{
			can=1;
			break;
		}
		L+=a[p]+n-1,R+=sum;
	}
	if(can) puts("YES");
	else puts("KEK");
	return 0;
}
/*
2 100000000
1 2

4 3
1 2 3 2

5 8
1 2 3 2 1
*/
