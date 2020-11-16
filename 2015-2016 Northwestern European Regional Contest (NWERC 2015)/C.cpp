#include<bits/stdc++.h>
using namespace std;

#define db int
const db EPS=1e-9;
inline int sign(db a){return a<-EPS?-1:a>EPS;}
inline int cmp(db a,db b){return sign(a-b);}
struct P
{
    db x,y;
    P(){}
    P(db x,db y):x(x),y(y){}
    P operator+(P p){return {x+p.x,y+p.y};}
    P operator-(P p){return {x-p.x,y-p.y};}
    P operator*(db d){return {x*d,y*d};}
    P operator/(db d){return {x/d,y/d};}
    bool operator<(P p) const
    {
        int c=cmp(x,p.x);
        if(c) return c==-1;
        return cmp(y,p.y)==-1;
    }
    bool operator==(P o) const
    {
        return cmp(x,o.x)==0&&cmp(y,o.y)==0;
    }
    db distTo(P p){return (*this-p).abs();}
    db alpha(){return atan2(y,x);}
    void read(){scanf("%d%d",&x,&y);}
    void write(){printf("(%d,%d)\n",x,y);}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x+y*y;}
    P rot90(){return P(-y,x);}
    P unit(){return *this/abs();}
    int quad() const {return sign(y)==1||(sign(y)==0&&sign(x)>=0);}
    db dot(P p){return x*p.x+y*p.y;}
    db det(P p){return x*p.y-y*p.x;}
};

//For segment
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

bool chkLL(P p1,P p2,P q1,P q2) //0:parallel
{
    db a1=cross(q1,q2,p1),a2=-cross(q1,q2,p2);
    return sign(a1+a2)!=0;
}

P isLL(P p1,P p2,P q1,P q2) //crossover point if chkLL()
{
    db a1=cross(q1,q2,p1),a2=-cross(q1,q2,p2);
    return (p1*a2+p2*a1)/(a1+a2);
}

bool intersect(db l1,db r1,db l2,db r2)
{
    if(l1>r1) swap(l1,r1);if(l2>r2) swap(l2,r2);
    return !(cmp(r1,l2)==-1||cmp(r2,l1)==-1);
}

bool isSS(P p1,P p2,P q1,P q2)
{
    return intersect(p1.x,p2.x,q1.x,q2.x)&&intersect(p1.y,p2.y,q1.y,q2.y)&&
    crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<=0&&crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<=0;
}

bool isSS_strict(P p1,P p2,P q1,P q2)
{
    return crossOp(p1,p2,q1)*crossOp(p1,p2,q2)<0
    &&crossOp(q1,q2,p1)*crossOp(q1,q2,p2)<0;
}

bool isMiddle(db a,db m,db b)
{
    return sign(a-m)==0||sign(b-m)==0||(a<m!=b<m);
}

bool isMiddle(P a,P m,P b)
{
    return isMiddle(a.x,m.x,b.x)&&isMiddle(a.y,m.y,b.y);
}

bool onSeg(P p1,P p2,P q)
{
    return crossOp(p1,p2,q)==0&&isMiddle(p1,q,p2);
}

bool onSeg_strict(P p1,P p2,P q)
{
    return crossOp(p1,p2,q)==0&&sign((q-p1).dot(p1-p2))*sign((q-p2).dot(p1-p2))<0;
}

int fa[1005],mx[1005],siz[1005],cnt[1005],n,m;
P well[1005];
struct pipe
{
	P st,ed;
	int num;
}pp[1005];

int _find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=_find(fa[x]);
}

void _merge(int x,int y)
{
	x=_find(x),y=_find(y);
	if(x!=y) fa[x]=y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) well[i].read();
	for(int i=1,num;i<=m;i++)
	{
		scanf("%d",&num);
		pp[i].ed.read();
		pp[i].st=well[num];
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(pp[i].st==pp[j].st) continue;
			if(isSS(pp[i].st,pp[i].ed,pp[j].st,pp[j].ed))
			{
				cnt[i]++,cnt[j]++;
				_merge(i,j);
			}
		}
	for(int i=1;i<=m;i++)
	{
		siz[fa[i]]+=cnt[i];
		mx[fa[i]]=max(mx[fa[i]],cnt[i]);
	}
	int flag=1;
	for(int i=1;i<=m;i++)
		if(mx[i]&&mx[i]*2!=siz[i]) flag=0;
	if(flag) printf("possible"); else printf("impossible");
    return 0;
}
