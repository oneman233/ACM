#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-10;
 
double x;
 
bool eql(double a,double b){
	if(fabs(a-b)<eps) return 1;
	return 0;
}
 
int pow(int x){
	int res=1;
	for(int i=1;i<=x;++i)
		res*=10;
	return res;
}
 
int len(ll x){
	ll t=x;
	int l=0;
	while(x){
		l++;
		x/=10;
	}
	return l;
}
 
double gao(ll a){
	int t=a,l=len(a);
//	cout<<a<<' '<<l<<endl;
	int k=pow(l-1);
	int b=a%k*10+a/k;
//	cout<<a<<' '<<b<<endl;
	return (double)b;
}
 
unordered_map<ll,bool> mp;
 
int main()
{
	scanf("%lf",&x);
	if(x>11.0){
		puts("No solution");
		return 0;
	}
	vector<ll> v;
	for(ll i=1;i<=65000000;++i){
		if(eql(i*x,gao(i))){
//			printf("%lld\n",i);
			v.push_back(i);
		}
	}
	if(v.size()==0) puts("No solution");
	else{
		for(auto i:v){
			int l=len(i);
			if(l*2<=8)
				v.push_back(i+i*pow(l));
		}
		for(auto i:v)
			if(!mp[i])
			printf("%lld\n",i),
			mp[i]=1;
	}
	return 0;
}
