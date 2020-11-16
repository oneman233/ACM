#include <bits/stdc++.h>
using namespace std;
inline int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

char c[5];
int _,n,a[10005],cur;
pair<int,int> p[10005];
bool v[10005];

void gao(){
	for(int i=1;i<=n;++i) v[i]=0;
	int ans=0;
	for(int i=1;i<cur;i++){
		//if(v[i]) continue;
		for(int j=cur;j<=n;j++){
			if(!v[j]&&__gcd(p[i].second,p[j].second)!=1){
				v[i]=v[j]=1;
				ans++;
				break;
			}
		}
	}
	//for(auto &i:m[1]) if(v[i]) ans++;
	printf("%d\n",n-ans);
}

int main()
{
	//freopen("b.in","r",stdin);
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		for(int i=1;i<=n;++i){
			scanf("%s",c);
			if(c[0]=='M') p[i]={0,a[i]};
			else p[i]={1,a[i]};
		}
		sort(p+1,p+n+1);
		cur=1;
		while(p[cur].first==0&&cur<=n) cur++;
		gao();
	}
	return 0;
}
/*
2
2
3 6
M F
5
5 6 7 10 21
F F F M M
*/
