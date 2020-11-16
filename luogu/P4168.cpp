#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int inf=0x3f3f3f3f;
inline int read(){
    char ch=getchar();int s=0,w=1;
    while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}
    while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
    return s*w;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}

int n,m,lastans=0,l,r;
int a[maxn],b[maxn];
int cnt[maxn],ans[1000][1000],num[1000][1000];
int id[maxn],from[1000],to[1000],tot;
vector<int> pos[maxn];

void pre(){
	tot=sqrt(n);
	for(int i=1;i<=tot;++i){
		from[i]=(i-1)*tot+1;
		to[i]=i*tot;
	}
	if(to[tot]<n) tot++,from[tot]=to[tot-1]+1,to[tot]=n;
	for(int i=1;i<=tot;++i)
		for(int j=from[i];j<=to[i];++j) id[j]=i;
	for(int i=1;i<=tot;++i){
		for(int j=i;j<=tot;++j){
			num[i][j]=-inf,ans[i][j]=inf;
			for(int k=from[i];k<=to[j];++k) cnt[a[k]]=0;
			for(int k=from[i];k<=to[j];++k){
				cnt[a[k]]++;
				if(cnt[a[k]]>num[i][j]){
					num[i][j]=cnt[a[k]];
					ans[i][j]=a[k];
				}
				else if(cnt[a[k]]==num[i][j]&&
				a[k]<ans[i][j])
					ans[i][j]=a[k];
			}
		}
	}
	for(int i=1;i<=n;++i)
		pos[a[i]].push_back(i);
}

void solve(){
//	l=(l+lastans-1)%n+1;
//	r=(r+lastans-1)%n+1;
	l^=lastans;
	r^=lastans;
	if(l>r){
		int t=l;
		l=r;
		r=t;
	}
	int tnum=-inf,tans=inf;
	int pl=id[l],pr=id[r];
	if(pl==pr){
		for(int i=l;i<=r;++i){
			int t1=lower_bound(pos[a[i]].begin(),
			pos[a[i]].end(),l)-pos[a[i]].begin();
			int t2=upper_bound(pos[a[i]].begin(),
			pos[a[i]].end(),r)-pos[a[i]].begin();
			if(t2-t1>tnum){
				tnum=t2-t1;
				tans=a[i];
			}
			else if(t2-t1==tnum&&a[i]<tans)
				tans=a[i];
		}
	}
	else{
		tnum=num[pl+1][pr-1],tans=ans[pl+1][pr-1];
		for(int i=l;i<=to[id[l]];++i){
			int t1=lower_bound(pos[a[i]].begin(),
			pos[a[i]].end(),l)-pos[a[i]].begin();
			int t2=upper_bound(pos[a[i]].begin(),
			pos[a[i]].end(),r)-pos[a[i]].begin();
			if(t2-t1>tnum){
				tnum=t2-t1;
				tans=a[i];
			}
			else if(t2-t1==tnum&&a[i]<tans)
				tans=a[i];
		}
		for(int i=from[id[r]];i<=r;++i){
			int t1=lower_bound(pos[a[i]].begin(),
			pos[a[i]].end(),l)-pos[a[i]].begin();
			int t2=upper_bound(pos[a[i]].begin(),
			pos[a[i]].end(),r)-pos[a[i]].begin();
			if(t2-t1>tnum){
				tnum=t2-t1;
				tans=a[i];
			}
			else if(t2-t1==tnum&&a[i]<tans)
				tans=a[i];
		}
	}
//	write(b[tans]);
//	puts("");
//	lastans=b[tans];
	write(tnum);
	puts("");
	lastans=tnum;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=a[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	pre();
	for(int i=1;i<=m;++i){
		l=read(),r=read();
		solve();
	} 
	return 0;
}
