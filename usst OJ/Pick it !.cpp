#include <bits/stdc++.h>
using namespace std;
const int maxn=200000;

int n;
struct point
{
    int x,y;

}p[maxn+5];

int operator * (point &a,point &b)
{
    return (a.x)*(b.y)-(a.y)*(b.x);
}

int r(int x)
{
    if(x!=n)
        return x+1;
    else
        return 1;
}

int howmany(point &a,point &b)
{
    return __gcd(abs(a.x-b.x),abs(a.y-b.y))+1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d %d",&p[i].x,&p[i].y);
    double area=0;
    for(int i=1;i<=n;++i)
        area+=p[i]*p[r(i)]/2.0;
    area*=-1.0;
    int online=0;
    for(int i=1;i<=n;++i)
        online+=howmany(p[i],p[r(i)]);
    online-=n;
    cout<<floor(area+1.0-online/2);
    return 0;
}
/*
4
0 0
3 4
0 6
8 4
3
1 0
0 0
1 1
4
1 0
0 -1
-1 0
0 1
*/
