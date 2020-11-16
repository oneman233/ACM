#include <bits/stdc++.h>
using namespace std;

int t,n,a,b;
int cnt[3];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i) scanf("%d",&a),cnt[a%3]++;
		for(int i=1;i<=n;++i) scanf("%d",&b),cnt[b%3]++;
		if(cnt[1]==2*n||cnt[2]==2*n){printf("YES\n");continue;}
		if(cnt[0]>n){printf("NO\n");continue;}
		if((cnt[0]<=1&&cnt[1]&&cnt[2])||(cnt[0]==2&&cnt[1]%2==0)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
