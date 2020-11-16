#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,dif[200005],l[200005],r[200005],dl[200005],dr[200005];
pii p[200005];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",l+i,r+i);
		r[i]--;
		dif[l[i]]++;
		dif[r[i]+1]--;
		dl[l[i]]++;
		dr[r[i]]++;
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=100000;i++)
		dl[i]+=dl[i-1],dr[i]+=dr[i-1],
		dif[i]+=dif[i-1],ans1=max(ans1,dif[i]);
	for(int i=0;i<n;i++)
	{
		int cnt=dl[r[i]]-dr[l[i]-1];
		ans2=max(ans2,cnt);
		//printf("%d %d %d\n",p[i].first,p[i].second,cnt);
	}
	printf("%d %d",ans2,ans1);
	return 0;
}
