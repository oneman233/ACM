#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int gao(ll n){
	int ans=0;
	while(n){
		if(n&1) ans++;
		n/=2;
	}
	return ans;
}

int main(){
	cin>>n;
	cout<<(1ll<<gao(n));
	return 0;
}
