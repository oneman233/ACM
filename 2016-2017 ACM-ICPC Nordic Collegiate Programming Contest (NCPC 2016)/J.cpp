#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y; cin>>x>>y;
	for(int i=-179; i<181; ++i)
		if((x+i+360)%360==y)
			printf("%d",i);
//	int ans;
//	if(x>y){
//		ans=x-y;
//		if(ans>180) ans=360-ans;
//		else ans=-ans;
//	}else{
//		ans=y-x;
//		if(ans>180) ans=360-ans;
//		else ans=ans;
//	}
//	if(ans==-180)ans=180;
//	printf("%d",ans);
	return 0;
}
