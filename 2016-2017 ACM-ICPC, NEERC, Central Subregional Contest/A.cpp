#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&k);
	printf("%d",max(2,(n*2+k-1)/k));
	return 0;
}
