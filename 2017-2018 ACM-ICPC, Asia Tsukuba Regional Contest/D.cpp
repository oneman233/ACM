#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,dif[200005],l[200005],r[200005],difl[200005],difr[200005];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",l+i,r+i);
		r[i]--;
		dif[l[i]]++;
		dif[r[i]+1]--;
		difl[l[i]]++;
		difr[r[i]]++;
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=100000;i++) 
		difl[i]+=difl[i-1],difr[i]+=difr[i-1],
		dif[i]+=dif[i-1],ans1=max(ans1,dif[i]);
	for(int i=0;i<n;i++)
	{
		int k=difl[r[i]]-difr[l[i]-1];
		ans2=max(ans2,k);
		//printf("qaq %d %d\n",p[i].second,p[i].first);
		//printf("QAQ %d\n",sum(p[i].first)-sum(p[i].second-1));
	}
	printf("%d %d",ans2,ans1);
	return 0;
}
