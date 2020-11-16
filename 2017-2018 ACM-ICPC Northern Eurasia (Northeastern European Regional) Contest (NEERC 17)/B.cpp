#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,w,h;
vector<ll> v;

int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&w,&h);
	int s=2*(a*b+a*c+b*c);
	if(s>w*h) return puts("No"),0;
	v.push_back(a);v.push_back(b);v.push_back(c);
	sort(v.begin(),v.end());
	do
	{
		a=v[0],b=v[1],c=v[2];
		//
		if(w>=(a+c)&&h>=(3*b+a+c))
			return puts("Yes"),0;
		if(h>=(a+c)&&w>=(3*b+a+c))
			return puts("Yes"),0;
		//
		if(w>=(2*b+2*c)&&h>=(a+2*c))
			return puts("Yes"),0;
		if(h>=(2*b+2*c)&&w>=(a+2*c))
			return puts("Yes"),0;
		//
		if(w>=(a+b+c)&&h>=(2*a+b+c))
			return puts("Yes"),0;
		if(h>=(a+b+c)&&w>=(2*a+b+c))
			return puts("Yes"),0;
		//
		if(w>=(a+2*b+c)&&h>=(a+2*c))
			return puts("Yes"),0;
		if(h>=(a+2*b+c)&&w>=(a+2*c))
			return puts("Yes"),0;
	}
	while(next_permutation(v.begin(),v.end()));
	puts("No");
	return 0;
}
/*
10 1 8
9 39
*/
