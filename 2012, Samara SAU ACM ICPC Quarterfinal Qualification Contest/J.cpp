#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1000000;

int n,p,q;
int a[maxn+5];
int pre[maxn+5],suf[maxn+5];
int tot;
int x;
char s[20];

int main()
{
	scanf("%d%d",&n,&p);
	tot=n;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) pre[i]=i-1;
	pre[maxn]=n;
	for(int i=0;i<n;++i) suf[i]=i+1;
	suf[n]=maxn;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='p')
			printf("%d\n",a[p]);
		else if(s[0]=='m')
		{
			if(s[4]=='L')
			{
				if(pre[p]!=0)
					p=pre[p];
			} 
			else
			{
				if(suf[p]!=maxn)
					p=suf[p];
			}
		}
		else if(s[0]=='i')
		{
			scanf("%d",&x);
			if(s[6]=='L')
			{
				a[++tot]=x;
				pre[tot]=pre[p];
				suf[tot]=p;
				//
				suf[pre[p]]=tot;
				pre[p]=tot;
			}
			else
			{
				a[++tot]=x;
				pre[tot]=p;
				suf[tot]=suf[p];
				//
				pre[suf[p]]=tot;
				suf[p]=tot;
			}
		}
	}
	return 0;
}
