#include<bits/stdc++.h>
using namespace std;

#define db long double
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
    void read(){scanf("%Lf%Lf",&x,&y);}
    void write(){printf("(%.10Lf,%.10Lf)\n",x,y);}
    db abs(){return sqrt(abs2());}
    db abs2(){return x*x+y*y;}
    P rot90(){return P(-y,x);}
    P unit(){return *this/abs();}
    int quad() const {return sign(y)==1||(sign(y)==0&&sign(x)>=0);}
    db dot(P p){return x*p.x+y*p.y;}
    db det(P p){return x*p.y-y*p.x;}
    P rot(db an){return {x*cos(an)-y*sin(an),x*sin(an)+y*cos(an)};}
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

P proj(P p1,P p2,P q)
{
    P dir=p2-p1;
    return p1+dir*(dir.dot(q-p1)/dir.abs2());
}

P reflect(P p1,P p2,P q)
{
    return proj(p1,p2,q)*2-q;
}

db nearest(P p1,P p2,P q)
{
    P h=proj(p1,p2,q);
    if(isMiddle(p1,h,p2))
        return q.distTo(h);
    return min(p1.distTo(q),p2.distTo(q));
}

db disSS(P p1,P p2,P q1,P q2) //dist of 2 segments
{
    if(isSS(p1,p2,q1,q2)) return 0;
    return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)),min(nearest(q1,q2,p1),nearest(q1,q2,p2)));
}

db rad(P p1,P p2)
{
    return atan2l(p1.det(p2),p1.dot(p2));
}

int n,m;
P a[100005],b[100005];

inline db f(P &p1,P &p2,P &q1,P &q2,db x)
{
	P A=p1+(p2-p1)*x;
	P B=q1+(q2-q1)*x;
	return A.distTo(B);
}

db cal(P p1,P p2,P q1,P q2)
{
	//if(!isSS(p1,p2,q1,q2))
	//	return min(p1.distTo(q1),p2.distTo(q2));
	db up=1,low=0,m1,m2;
    for(int i=0;i<100;i++)  
    {  
        m1=low+(up-low)/3;  
        m2=up-(up-low)/3;  
        if(cmp(f(p1,p2,q1,q2,m1),f(p1,p2,q1,q2,m2))==-1) up=m2;  
        else low=m1;  
    }
    //printf("sanfen: %.10Lf\n",up);
    return f(p1,p2,q1,q2,(low+up)/2);  
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) a[i].read();
	scanf("%d",&m);
	for(int i=0;i<m;i++) b[i].read();
    int i=0,j=0;
    P nowa=a[0],nowb=b[0],ea,eb;
    db ans=1e20;
    while(i<n-1&&j<m-1)
    {
    	if(cmp(nowa.distTo(a[i+1]),nowb.distTo(b[j+1]))==1)
    	{
    		ea=nowa+(a[i+1]-nowa).unit()*nowb.distTo(b[j+1]);
    		eb=b[j+1];
    		j++;
    	}
    	else
    	{
    		eb=nowb+(b[j+1]-nowb).unit()*nowa.distTo(a[i+1]);
    		ea=a[i+1];
    		i++;
    	}
    	ans=min(ans,cal(nowa,ea,nowb,eb));
//    	nowa.write();
//    	ea.write();
//    	nowb.write();
//		eb.write();
//    	printf("\n");
		nowa=ea;
    	nowb=eb;
    }
    printf("%.10Lf",ans);
	return 0;
}

/*
2
0 0
0 1
2
1 0
1 1
*/
