#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
using namespace std;
const int maxn=300000;
typedef long long ll;

int n,a,b,tmpa,tmpb;
struct cat
{
    ll x,y,z;
}c1[maxn+5],c2[maxn+5];
ll sum1=0,sum2=0;

bool cmp1(cat a,cat b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    else
        return a.y<b.y;
}

bool cmp2(cat a,cat b)
{
    if(a.z!=b.z)
        return a.z>b.z;
    else
        return a.x>b.x;
}

int main()
{
    sci(n);
    scii(a,b);
    fo(i,0,n)
    {
        scll(c1[i].x,c1[i].y);
        c1[i].z=c1[i].x-c1[i].y;
        c2[i].x=c1[i].x,c2[i].y=c1[i].y,c2[i].z=c2[i].z;
    }
    sort(c1,c1+n,cmp1);
    tmpa=a,tmpb=b;
    while(tmpa--)
        c1[0].x*=2;
    c1[0].z=c1[0].x-c1[0].y;
    fo(i,0,n)
    {
        if(tmpb!=0&&c1[i].z>0)
        {
            c1[i].y=c1[i].x;
            --tmpb;
        }
        else
            break;
    }
    fo(i,0,n)
        sum1+=c1[i].y;
    sort(c2,c2+n,cmp2);
    tmpa=a,tmpb=b;
    while(tmpa--)
        c2[0].x*=2;
    c2[0].z=c2[0].x-c2[0].y;
    fo(i,0,n)
    {
        if(tmpb!=0&&c2[i].z>0)
        {
            c2[i].y=c2[i].x;
            --tmpb;
        }
    }
    fo(i,0,n)
        sum2+=c2[i].y;
    prl(max(sum1,sum2));
    return 0;
}
/*
2 5 251754
26 74
19 113
*/
/*
10 15 5
31 25
1 1
1 18
2 17
12 9
19 21
18 6
23 17
1 23
27 30
*/
