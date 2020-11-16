#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
vector<pair<pair<ll,ll>,ll> > q,vec;

ll k;
void go(ll x,ll y,ll z)
{
	ll tmp=k*y+k*z-x;
	if(tmp>0) vec.push_back(make_pair(make_pair(tmp,y),z));	
}

int main()
{
	ll n;
	scanf("%lld%lld",&k,&n);
	q.push_back(make_pair(make_pair(0,1),k));
	pair<pair<ll,ll>,ll> now;
	while(1)
	{
		for(int i=0;i<q.size();i++) {
			now=q[i];
			ll x=now.first.first,y=now.first.second,z=now.second;
			if(!s.count(x)&&!s.count(y)&&!s.count(z)&&x!=y&&y!=z&&z!=x&&x>0&&y>0&&z>0) {
				s.insert(x); s.insert(y); s.insert(z);
				printf("%lld %lld %lld\n",x,y,z);
				
				n--;
				if(n==0) return 0;
			}
			go(x,y,z); go(y,x,z); go(z,x,y);
			
		}	
		q.clear();
		for(int i=0;i<vec.size();i++) q.push_back(vec[i]);
		vec.clear();
	}
	
	return 0;
}
