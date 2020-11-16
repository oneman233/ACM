#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M=7*24*60;
char s[105][65],st[65];
bool okk[105];
int l,m,p[105],c[105],t[105],r[105];

inline bool ok(int i){
	return M*c[i]*t[i] >=ll(l)*(t[i]+r[i]); 
}

int main()
{
//char ch; while((ch=getchar())!=EOF) putchar(ch);
	scanf("%d%d",&l,&m);
	int mp=1<<30;
	for(int i=0;i<m;++i){
		char ch=getchar();//\n
//putchar(ch); 
		int ed=0;
		while((ch=getchar())!=',') st[ed++]=ch;
		st[ed]=0;
//printf("%s\n",st);
		strcpy(s[i],st);
		scanf("%d,%d,%d,%d",p+i,c+i,t+i,r+i);
		if(ok(i)) mp=min(mp,p[i]), okk[i]=1;
	}
	if(mp==1<<30) return puts("no such mower"),0;
	for(int i=0;i<m;++i) if(p[i]==mp && okk[i]) printf("%s\n",s[i]);
	return 0;
}
/*
7000 4
Grass Slayer 2000,9999,10,120,120
Slow-Mowe,999,1,120,240
Eco-cut X2,5499,2,25,35
Mowepower,5499,3,25,35
*/
