#include <bits/stdc++.h>
using namespace std;

int a[25];

int main(){
	int n; scanf("%d",&n);
	for(int i=0; i<n; ++i) scanf("%d",a+i);
	int ed=1<<n;
	long long ans=0;
	for(int i=1; i<ed; ++i){
		int cnt=0;
		for(int j=0, t=i;  t;  t>>=1, ++j){
			if(t&1) cnt|=a[j];
		}
		ans+=cnt; 
	}
	printf("%lld",ans);
	return 0;
}
