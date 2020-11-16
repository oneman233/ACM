#include <bits/stdc++.h>
using namespace std;
const int N=10005;
const double eps=1e-9;

int n,m,k;
struct node{
	double x,y,r;
}o[N];
int f[N];
int _find(int x){
	if(f[x]!=x) f[x]=_find(f[x]);
	return f[x];
}
void _merge(int x,int y){
	x=_find(x),y=_find(y);
	if(x!=y) f[x]=y;
}

double dis(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool smlepl(double a,double b){
	if(a<b||fabs(a-b)<eps) return 1;
	return 0;
}

void gao(){
	for(int i=1;i<=k+4;++i)
		f[i]=i;
	int x0=k+1,y0=k+2,xm=k+3,yn=k+4;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=k;++j){
			if(i==j) continue;
			if(smlepl(dis(o[i],o[j]),o[i].r+o[j].r))
				_merge(i,j);
		}
		if(o[i].y-o[i].r<=0) _merge(i,y0);
		if(o[i].y+o[i].r>=n) _merge(i,yn);
		if(o[i].x-o[i].r<=0) _merge(i,x0);
		if(o[i].x+o[i].r>=m) _merge(i,xm);
	}
	if(_find(y0)==_find(yn)||_find(x0)==_find(xm)||
	_find(x0)==_find(y0)||_find(xm)==_find(yn))
		puts("N");
	else puts("S");
}

int main(){
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=k;++i)
		scanf("%lf%lf%lf",&o[i].x,&o[i].y,&o[i].r);
	gao();
	return 0;
}
