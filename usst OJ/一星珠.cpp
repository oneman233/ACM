#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;

bool isp(int x)
{
	if(x==1)
		return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	int l,r;
	int ans=0;
	cin>>l>>r;
	for(int i=l;i<=r;++i)
		if(isp(i)||i==4)
			ans++;
	cout<<ans;
	return 0;
}
