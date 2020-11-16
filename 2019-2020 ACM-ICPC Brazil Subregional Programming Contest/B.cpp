#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;

int n,a[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int mx=-0x3f3f3f3f;
	int pos=-1;
	for(int i=1;i<=n;++i){
		if(a[i]>mx){
			mx=a[i];
			pos=i;
		}
	}
	if(pos==1) puts("S");
	else puts("N");
	return 0;
}
