#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;

int n,m,judge,x,y;
int a[maxn],tr[maxn*4],add[maxn*4];

void up(int p)
{
    tr[p]=tr[p*2]+tr[p*2+1];
}

void down(int p,int l,int r)
{
    if(add[p]!=0)
    {
        add[p*2]+=add[p];
        add[p*2+1]+=add[p];
        int m=(l+r)/2;
        tr[p*2]+=add[p]*(m-l+1);
        tr[p*2+1]+=add[p]*(r-m);
        add[p]=0;
    }
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(p*2,l,m);
    build(p*2+1,m+1,r);
    up(p);
}

void modify1(int p,int l,int r,int pos,int val)
{
    if(l==r&&l==pos)
    {
        tr[p]=val;
        return;
    }
    down(p,l,r);
    int m=(l+r)/2;
    if(pos<=m) modify1(p*2,l,m,pos,val);
    else if(pos>m) modify1(p*2+1,m+1,r,pos,val);
    up(p);
}

void modify2(int val)
{
    add[1]+=val;
}

int query(int p,int l,int r,int pos)
{
    if(l==r&&l==pos)
    {
        return tr[p];
    }
    down(p,l,r);
    int m=(l+r)/2,ans;
    if(pos<=m)
        ans=query(p*2,l,m,pos);
    else
        ans=query(p*2+1,m+1,r,pos);
    up(p);
    return ans;
}

int main()
{
    memset(add,0,sizeof(add));
    memset(tr,0,sizeof(tr));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--)
    {
        scanf("%d",&judge);
        if(judge==1)
        {
            scanf("%d %d",&x,&y);
            modify1(1,1,n,x,y);
        }
        else if(judge==2)
        {
            scanf("%d",&x);
            modify2(x);
        }
        else if(judge==3)
        {
            scanf("%d",&x);
            printf("%d\n",query(1,1,n,x));
        }
    }
    return 0;
}
