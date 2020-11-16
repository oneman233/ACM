#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
long long tmp;
priority_queue<long long> a;
priority_queue<ll,vector<ll>,greater<ll> >b;

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>tmp;
		a.push(tmp);
		b.push(tmp);
	}
	while(a.size()>1&&b.size()>1)
	{
		ll i=a.top();
		a.pop();
		ll j=a.top();
		a.pop();
		a.push(i*j+1);
		i=b.top();
		b.pop();
		j=b.top();
		b.pop();
		b.push(i*j+1);
	}
	cout<<b.top()<<" "<<a.top();
	return 0;
}
