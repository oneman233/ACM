#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld n,p,s,v;
ld s2=sqrt(2);

inline ld f(ld c)
{
	return n*pow(log2(n),c*s2)/p/1e9+s/v*(1+1/c);
}

int main()
{
	cin>>n>>p>>s>>v;
	ld l=0,ml,mr,r=1e9;
	for(int i=0;i<100;++i)
	{
		ml=l+(r-l)/3, mr=r-(r-l)/3;
		if(f(ml)<=f(mr)) r=mr;
		else l=ml;
	}
//	cout<<(ml+mr)/2<<' '<<f((ml+mr)/2);
	cout<<fixed<<setprecision(10);
	cout<<f((ml+mr)/2)<<' '<<(ml+mr)/2;
	return 0;
}
