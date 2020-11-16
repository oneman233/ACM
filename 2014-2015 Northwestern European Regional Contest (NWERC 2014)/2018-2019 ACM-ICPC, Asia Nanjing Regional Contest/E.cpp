#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=0x3f3f3f3f;

int n,m;
char ss[N],t[N],s[N];
int p[N*2];
ll dif[2*N];

int manache()
{
	s[0]='$';
	int j=1;
	for(int i=1;i<=n;++i)
	{
		s[j]='#';
		j++;
		s[j]=ss[i];
		j++;
	}
	s[j]='#';
	int mx=-inf,id,ans=-inf;
	for(int i=1;i<=j;++i)
	{
		if(mx>i) p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while(s[i-p[i]]==s[i+p[i]]) p[i]++;
		if(i+p[i]>mx)
			mx=i+p[i],id=i;
		ans=max(ans,p[i]-1);
	}
	return ans;
}

int nxt[N],pos[N];

void get_fail(char *s,int l)
{
	int i=0,j;
    j=nxt[0]=-1;
	while(i<l)
	{
		while(~j&&s[j]!=s[i]) j=nxt[j];
		nxt[++i]=++j;
	}
}

void kmp(char *s1,char *s2,int l1,int l2)
{
	int i=0,j=0;
	get_fail(s2,l2);
	while(i<l1)
	{
		while(~j&&s1[i]!=s2[j]) j=nxt[j];
		i++,j++;
		pos[i]=j;
	}
}

int main()
{
	scanf("%s",ss+1);
	scanf("%s",t+1);
	n=strlen(ss+1),m=strlen(t+1);
	reverse(ss+1,ss+1+n);
	kmp(ss+1,t+1,n,m);
	manache();
	//for(int i=1;i<=n;i++)
	//	printf("%d",pos[i]);
	for(int i=1;i<=2*n;i++)
	{
		if(s[i]=='#'&&p[i]>1)
			dif[(i+p[i]-1)/2+1]--,dif[(i+1)/2]++;//,printf("!%d %d++ %d--\n",i,(i+1)/2,(i+p[i])/2+1);
		else if(s[i]!='#')
			dif[(i+p[i]-1)/2+1]--,dif[i/2]++;//,printf("!%d %d++ %d--\n",i,i/2,(i+p[i]-1)/2+1);
	}
	ll sum=0;
	reverse(pos+1,pos+n+1);
	for(int i=2;i<=n;i++) dif[i]+=dif[i-1];
	reverse(dif+1,dif+n+1);
	for(int i=2;i<=n+1;i++) dif[i]+=dif[i-1];
	//reverse(pos+1,pos+n+1);
	//reverse(dif+1,dif+n+1);
	//dif[n+1]=0;
	for(int i=1;i<=n;i++) printf("%lld ",dif[i]);
	printf("\n");
	for(int i=1;i<=n;i++) printf("%d ",pos[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		sum+=dif[i+pos[i]]-dif[i];//*pos[i];
	printf("%lld\n",sum);
	return 0;
}
