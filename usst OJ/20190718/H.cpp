#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;

int n,q,x,y;
int arr[maxn];
int mx[maxn*4],pre[maxn*4],lst[maxn*4],sum[maxn*4];
int mxl[maxn*4],mxr[maxn*4],prer[maxn*4],lstl[maxn*4];

int ll(int p){return p*2;}
int rr(int p){return p*2+1;}
int mmax(int a,int b,int c){return max(a,max(b,c));}

void up(int p)
{

}

void build(int p,int l,int r)
{
    if(l==r){
        mx[p]=arr[l];
        pre[p]=arr[l];
        lst[p]=arr[l];
        sum[p]=arr[l];
        prer[p]=l;
        lstl[p]=l;
        mxl[p]=l;
        mxr[p]=l;
        return;
    }
    int m=(l+r)/2;
    build(ll(p),l,m);
    build(rr(p),m+1,r);
    up(p);
}

void ask(int p,int l,int r,int L,int R)
{

}

signed main()
{
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%lld",&arr[i]);
    build(1,1,n);
    return 0;
}
