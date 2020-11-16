#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	int Mh=0; long long sum=0;
	for(int i=0;i<n;++i){
		int h;
		scanf("%d",&h);
		sum+=h;
		Mh=max(Mh,h);
		if(t>=sum)
			printf("%lld\n",(t-sum)/Mh+2);
		else
			puts("1");
	}
	return 0;
}
