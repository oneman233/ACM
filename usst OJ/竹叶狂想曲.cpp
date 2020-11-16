#include <iostream>
using namespace std;
const int maxn=1000000;

struct node
{
    int l,r,v=0,tag=0;
}x[4*maxn+1],y[4*maxn+1];
int n,tx,ty;
int op,x1=-100,y1=-100,x2=-100,y2=-100;

int ls(int p){return p*2;}
int rs(int p){return p*2+1;}

void buildx(int p,int l,int r)
{
    ///cout<<p<<endl;
    x[p].l=l;x[p].r=r;
    if(x[p].l==x[p].r)
        return;
    int m=(l+r)/2;
    buildx(ls(p),l,m);
    buildx(rs(p),m+1,r);
}

void buildy(int p,int l,int r)
{
    ///cout<<p<<endl;
    y[p].l=l;y[p].r=r;
    if(y[p].l==y[p].r)
        return;
    int m=(l+r)/2;
    buildy(ls(p),l,m);
    buildy(rs(p),m+1,r);
}

void upx(int p)
{
    x[p].v=x[ls(p)].v+x[rs(p)].v;
}

void downx(int p)
{
    x[ls(p)].tag+=x[p].tag;
    x[rs(p)].tag+=x[p].tag;
    x[ls(p)].v+=(x[ls(p)].r-x[ls(p)].l+1)*x[p].tag;
    x[rs(p)].v+=(x[rs(p)].r-x[rs(p)].l+1)*x[p].tag;
    x[p].tag=0;
}

void upy(int p)
{
    y[p].v=y[ls(p)].v+y[rs(p)].v;
}

void downy(int p)
{
    y[ls(p)].tag+=y[p].tag;
    y[rs(p)].tag+=y[p].tag;
    y[ls(p)].v+=(y[ls(p)].r-y[ls(p)].l+1)*y[p].tag;
    y[rs(p)].v+=(y[rs(p)].r-y[rs(p)].l+1)*y[p].tag;
    y[p].tag=0;
}

int qx(int l,int r,int p)
{
    int ans=0;
    if(x[p].l>=l&&x[p].r<=r){
        ans+=x[p].v;
        return ans;
    }
    if(x[p].tag!=0)
        downx(p);
    int m=(x[p].l+x[p].r)/2;
    if(l<=m)
        ans+=qx(l,r,ls(p));
    if(r>=m)
        ans+=qx(l,r,rs(p));
    return ans;
}

int qy(int l,int r,int p)
{
    int ans=0;
    if(y[p].l>=l&&y[p].r<=r){
        ans+=y[p].v;
        return ans;
    }
    if(y[p].tag!=0)
        downy(p);
    int m=(y[p].l+y[p].r)/2;
    if(l<=m)
        ans+=qy(l,r,ls(p));
    if(r>=m)
        ans+=qy(l,r,rs(p));
    return ans;
}

void addx(int l,int r,int p,int v)
{
    ///cout<<p<<endl;
    if(x[p].l==0&&x[p].r==0)///无信息
        return;
    if(x[p].l>=l&&x[p].r<=r){
        x[p].v+=(x[p].r-x[p].l+1)*v;
        x[p].tag+=v;
        return;
    }
    if(x[p].tag!=0)
        downx(p);
    int m=(x[p].l+x[p].r)/2;
    if(l<=m)
        addx(l,r,ls(p),v);
    if(r>=m)
        addx(l,r,rs(p),v);
    upx(p);
}

void addy(int l,int r,int p,int v)
{
    ///cout<<p<<endl;
    if(y[p].l==0&&y[p].r==0)///无信息
        return;
    if(y[p].l>=l&&y[p].r<=r){
        y[p].v+=(y[p].r-y[p].l+1)*y[p].tag;
        y[p].tag+=v;
        return;
    }
    if(y[p].tag!=0)
        downy(p);
    int m=(l+r)/2;
    if(l<=m)
        addy(l,r,ls(p),v);
    if(r>=m)
        addy(l,r,rs(p),v);
    upy(p);
}

void debug()
{
    for(int i=maxn*3;i<=maxn*4;++i)
        cout<<x[i].l<<" "<<x[i].r<<endl;
}

int main()
{
    buildx(1,1,maxn);
    buildy(1,1,maxn);
    ///debug();
    scanf("%d",&n);
    while(n--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            addx(x1,x2,1,1);
            addy(y1,y2,1,1);
        }
        else if(op==2){
            scanf("%d",&tx);
            printf("%d",qx(tx,tx,1));
        }
        else if(op==3){
            scanf("%d",&ty);
            printf("%d",qy(ty,ty,1));
        }
        else if(op==4){
            if(x1!=-100&&y1!=-100&&x2!=-100&&y2!=-100){
                addx(x1,x2,1,-1);
                addy(y1,y2,1,-1);
            }
        }
    }
    return 0;
}
