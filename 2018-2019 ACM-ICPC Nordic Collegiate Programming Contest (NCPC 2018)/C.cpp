#include <bits/stdc++.h>
using namespace std;

int n,d[366];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&d[i]);
	int ans=0;
	for(int i=1;i<=365;++i){
		int tmp=0;
		for(int j=1;j<=n;++j){
			if(d[j]>=i&&d[j]!=1000) break;
			if(d[j]!=1000) tmp+=i-d[j];
		}
//		cout<<tmp<<endl;
		if(i==365&&(tmp!=0||d[n]==365)){
			ans++;
			break;
		}
		if(tmp>=20){
			ans++;
			for(int j=1;j<=n;++j){
				if(d[j]>=i&&d[j]!=1000) break;
				d[j]=1000;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
