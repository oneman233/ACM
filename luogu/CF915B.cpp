#include <bits/stdc++.h>
using namespace std;

int n,pos,l,r;

int main()
{
    cin>>n>>pos>>l>>r;
    if(l==1&&r==n){
    	cout<<0;
    	return 0;
	}
	if(r==n){
		cout<<abs(pos-l)+1;
		return 0;
	}
	if(l==1){
		cout<<abs(pos-r)+1;
		return 0;
	}
	if(pos>=l&&pos<=r){
		cout<<(r-l)+min(pos-l,r-pos)+2;
	}
	else{
		cout<<max(abs(pos-l),abs(pos-r))+2;
	}
    return 0;
}
