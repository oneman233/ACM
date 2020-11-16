#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int inf=0x3f3f3f3f;

int n,op,x;

struct treap {
	int seed;
	inline int rand(){seed=seed*49147LL%INT_MAX;return seed;}
	int l[maxn],r[maxn],val[maxn],key[maxn],sz[maxn],w[maxn];
	int tot,rt,ans;
	treap(){seed=233;}
	inline void up(int p){sz[p]=sz[l[p]]+sz[r[p]]+w[p];}
	void lspin(int &k){
		int t=r[k];
		r[k]=l[t];
		l[t]=k;
		sz[t]=sz[k];
		up(k);
		k=t;
	}
	void rspin(int &k){
		int t=l[k];
		l[k]=r[t];
		r[t]=k;
		sz[t]=sz[k];
		up(k);
		k=t;
	}
	void ins(int &k,int x){
		if(!k){
			++tot;
			k=tot;
			sz[k]=w[k]=1;
			val[k]=x;
			key[k]=rand();
			return;
		}
		sz[k]++;
		if(val[k]==x) w[k]++;
		else if(val[k]<x){
			ins(r[k],x);
			if(key[r[k]]<key[k]) lspin(k);
			//maintain a small heap
		}
		else{
			ins(l[k],x);
			if(key[l[k]]<key[k]) rspin(k);
			//maintain a small heap
		}
	}
	void del(int &k,int x){
		if(!k) return;
		//can't find x
		if(val[k]==x){
			if(w[k]>1){
				w[k]--;
				sz[k]--;
				return;
			}
			if(l[k]==0||r[k]==0)
				k=l[k]+r[k];
			else if(key[l[k]]<key[r[k]]){
				rspin(k);
				del(k,x);
			}
			else{
				lspin(k);
				del(k,x);
			}
		}
		else if(val[k]<x){
			sz[k]--;
			del(r[k],x);
		}
		else{
			sz[k]--;
			del(l[k],x);
		}
	}
	int ask(int k,int x){
		if(!k) return 0;
		if(val[k]==x) return sz[l[k]]+1;
		else if(x>val[k]) return sz[l[k]]+w[k]+ask(r[k],x);
		else return ask(l[k],x);
	}
	int get(int k,int x){
		if(!k) return 0;
		if(x<=sz[l[k]]) return get(l[k],x);
		else if(x>sz[l[k]]+w[k]) return get(r[k],x-sz[l[k]]-w[k]);
		else return val[k];
	}
	void pre(int k,int x){
		if(!k) return;
		if(val[k]<x) ans=k,pre(r[k],x);
		else pre(l[k],x);
	}
	void suc(int k,int x){
		if(!k) return;
		if(val[k]>x) ans=k,suc(l[k],x);
		else suc(r[k],x);
	}
}t;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&op,&x);
		if(op==1)
			t.ins(t.rt,x);
		else if(op==2)
			t.del(t.rt,x);
		else if(op==3)
			printf("%d\n",t.ask(t.rt,x));
		else if(op==4)
			printf("%d\n",t.get(t.rt,x));
		else if(op==5){
			t.ans=0;
			t.pre(t.rt,x);
			printf("%d\n",t.val[t.ans]);
		}
		else if(op==6){
			t.ans=0;
			t.suc(t.rt,x);
			printf("%d\n",t.val[t.ans]);
		}
	}
	return 0;
}
