#include <bits/stdc++.h>
using namespace std;
const int maxn=10000005;

int n,ed[maxn],p[maxn],cnt=0,sz[maxn],fl[maxn],ch[maxn][26];
char s[maxn];

void ins(int x){
	int l=strlen(s),now=0;
	for(int i=0;i<l;++i){
		int v=s[i]-'a';
		if(!ch[now][v]) ch[now][v]=++cnt;
		now=ch[now][v];
		sz[now]++;
	}
	ed[x]=now;
}

void build(){
	int head=0,tail=0;
	for(int i=0;i<26;++i){
		if(ch[0][i]){
			q[++head]=ch[0][i];
			fl[ch[0][i]]=0;
		}
	}
	while(head<tail){
		int x=h[++head];
		for(int i=0;i<26;++i){
			if(){
				
			}
			else 
		} 
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		ins(i);
	}
	build();
	cal();
	return 0;
}
