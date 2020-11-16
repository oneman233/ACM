#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ca,ba,pa,cr,br,pr;

int main()
{
	scanf("%d%d%d",&ca,&ba,&pa);
	scanf("%d%d%d",&cr,&br,&pr);
	int ans=0;
	if(cr>ca) ans+=cr-ca;
	if(br>ba) ans+=br-ba;
	if(pr>pa) ans+=pr-pa;
	printf("%d",ans);
	return 0;
}
