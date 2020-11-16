#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r;
set<ll> s;

ll cal(ll x)
{
	if(x==-1) return 0;
	s.clear();
	ll ret=0;
	for(int i=1;i<=63;i++)
		for(int j=1;j<=63;j++)
		{
			int tot=0,k=0;
			ll now=0;
			while(1)
			{
				k++;
				if(k&1) tot+=i; else tot+=j;
				if(tot>63) break;
				if(k&1)
					for(int t=0;t<i;t++) now<<=1,now+=1;
				else 
					for(int t=0;t<j;t++) now<<=1;
				if(now>x) break;
				if(s.find(now)==s.end()) ret++,s.insert(now);
				//printf("!! %lld %d %d\n",now,i,j);
			}
		}
	return ret;	
}

int main()
{
	scanf("%lld%lld",&l,&r);
	printf("%lld",cal(r)-cal(l-1));
	return 0;
}
